#include "Room.hpp"
#include "EnemyHandler.hpp"
#include "FightHandler.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "SystemSettings.hpp"
#include "Weapon.hpp"

#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\Graphics\Color.hpp>
#include <SFML\Graphics\Sprite.hpp>

#include <time.h>

//TODO: Get items and doors from Twitter
//		Will just be random in the first iteration
Room::Room()
{
	//================================================================================================
	// Neighboring rooms
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 4; i++)
	{
		m_neighboringRoom[i].room = nullptr;
		m_neighboringRoom[i].locked = rand() % 2;
	}
	m_entryPoint = -1;			// This room is the root

	//================================================================================================
	// Contents of room
	m_fightHandler = new FightHandler;
	m_enemyHandler = new EnemyHandler;
	for (int i = 0; i < 5; i++)
	{
		m_enemyHandler->CreateEnemy();
	}

	Item* weapon = new Weapon("Axe.png");
	weapon->SetPosition(sf::Vector2f(WINDOW_WIDTH * 0.5f, WINDOW_HEIGHT * 0.5f));
	m_itemsInRoom.push_back(weapon);

	//================================================================================================
	// Visuals of room
	m_roomShape = new sf::RectangleShape(sf::Vector2f(WINDOW_WIDTH * 0.9f, WINDOW_HEIGHT * 0.9f));
	m_roomShape->setOrigin(sf::Vector2f(WINDOW_WIDTH * 0.45f, WINDOW_HEIGHT * 0.45f));
	m_roomShape->setPosition(sf::Vector2f(WINDOW_WIDTH * 0.5f, WINDOW_HEIGHT * 0.5f));
	m_roomShape->setFillColor(sf::Color::Color(140, 54, 1));
	m_roomShape->setOutlineColor(sf::Color::Color(255, 255, 255));
	m_roomShape->setOutlineThickness(5.0f);

	for (int i = 0; i < 4; i++)
	{
		m_doors[i] = new sf::RectangleShape(sf::Vector2f(80, 10));
		m_doors[i]->setOrigin(40, 5);
		m_doors[i]->setRotation(i * 90);
		m_doors[i]->setPosition(DoorPositionArray[i]);

		m_doors[i]->setFillColor(m_neighboringRoom[i].locked ? sf::Color::Red : sf::Color::Green);
	}
}
Room::Room(Room* parent, int parentLocation) : Room()
{	
	m_entryPoint = parentLocation;
	m_neighboringRoom[m_entryPoint].room = parent;			// The room which created this
	m_neighboringRoom[m_entryPoint].locked = false;			// Since player came from this, it's not locked
	m_doors[m_entryPoint]->setFillColor(sf::Color::Green);	// --||--
}
Room::~Room()
{
	if (m_enemyHandler)
	{
		delete m_enemyHandler;
		m_enemyHandler = nullptr;
	}
	if (m_fightHandler)
	{
		delete m_fightHandler;
		m_fightHandler = nullptr;
	}

	for (int i = 0; i < 4; i++)
	{
		// Delete each room created after this one
		if (i != m_entryPoint)
		{
			delete m_neighboringRoom[i].room;
			m_neighboringRoom[i].room = nullptr;
		}
	}
	if (m_roomShape)
	{
		delete m_roomShape;
		m_roomShape = nullptr;
	}
	for (int i = 0; i < 4; i++)
	{
		if (m_doors[i])
		{
			delete m_doors[i];
			m_doors[i] = nullptr;
		}
	}
	for (unsigned int i = 0; i < m_itemsInRoom.size(); i++)
	{
		if (m_itemsInRoom[i])
		{
			delete m_itemsInRoom[i];
			m_itemsInRoom[i] = nullptr;
		}
	}
}

bool Room::CreateNeighboringRoom(int location)
{
	if (location < 0 || location > 3)
		return false;

	if (m_neighboringRoom[location].locked)
		return false;

	// If the room doesn't already exist
	if (!m_neighboringRoom[location].room)
		m_neighboringRoom[location].room = new Room(this, (location + 2) % 4);	// Location of parent, from the new room

	return true;
}
Room* Room::GetNeighboringRoom(int location)
{
	// Nullptr if location is invalid or room does not exist
	return location > -1 && location < 4 ? m_neighboringRoom[location].room : nullptr;
}
bool Room::IsNeighboringRoomLocked(int location)
{
	// False if location is invalid or room is locked
	return location > -1 && location < 4 ? m_neighboringRoom[location].locked : false;
}

void Room::CheckItemPickUp(Player* player)
{
	Item* closestItem = nullptr;
	float minDist = 1000000.0f;		// Near infinite
	int itemindex = -1;

	for (int i = 0; i < m_itemsInRoom.size(); i++)
	{
		sf::Vector2f distVec = player->GetPosition() - m_itemsInRoom.at(i)->GetPosition();
		float dist = sqrtf(pow(distVec.x, 2) + pow(distVec.y, 2));

		if (dist > player->GetRadius() + m_itemsInRoom.at(i)->GetSprite()->getLocalBounds().width * 0.5f)
			continue;
		if (dist >= minDist)
			continue;

		itemindex = i;
		minDist = dist;
	}

	// The vector of items was empty
	if (itemindex == -1)
		return;

	closestItem = m_itemsInRoom.at(itemindex);

	if (!closestItem)
		return;
	
	if (player->GiveItem(closestItem))
		m_itemsInRoom.erase(m_itemsInRoom.begin() + itemindex);
}
void Room::SpawnItem(Item* item, sf::Vector2f pos)
{
	// TODO: make these values random within the boundries of the room
	item->SetPosition(pos);

	m_itemsInRoom.push_back(item);
}

void Room::Update()
{
	m_enemyHandler->Update();
	m_fightHandler->Update();
}

void Room::StartFightInRoom(Player* player)
{
	for (unsigned int i = 0; i < m_enemyHandler->GetNrOfEnemies(); i++)
	{
		m_fightHandler->StartFight(player, m_enemyHandler->GetEnemy(i));
	}
}


void Room::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//================================================================================================
	// Visuals of room
	target.draw(*m_roomShape, states);
	for (int i = 0; i < 4; i++)
	{
		target.draw(*m_doors[i], states);
	}

	//================================================================================================
	// Contents of room
	target.draw(*m_enemyHandler, states);

	for (int i = 0; i < m_itemsInRoom.size(); i++)
	{
		target.draw(*m_itemsInRoom.at(i), states);
	}
}