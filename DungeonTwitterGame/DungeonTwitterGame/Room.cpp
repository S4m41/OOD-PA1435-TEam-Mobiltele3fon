#include "Room.hpp"
#include "Weapon.hpp"
#include "EnemyHandler.hpp"
#include "FightHandler.hpp"
#include "PlayerHandler.hpp"
#include "Player.hpp"

#include "SystemSettings.hpp"
#include "ItemEntity.hpp"

#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\Graphics\Color.hpp>

#include <vector>
#include <iostream>

Room::Room(std::wstring seedName) : Room(new Door(seedName, nullptr))
{

}

//TODO: Get items and doors from Twitter
//		Will just be random in the first iteration
Room::Room(Door* door)
{
	m_enemyHandler = new EnemyHandler;
	m_fightHandler = new FightHandler;


	for (int i = 0; i < 5; i++)
	{
		m_enemyHandler->CreateEnemy();
	}

	int entryPos = door->m_doorPositionIndex;

	door->m_toRoom = this;
	m_doors[0] = door;

	// leftDoor is a nullptr (aka m_locked) for the sake of testing
	// name = L" " == locked door
	m_doors[1] = new Door(L" ", this, (entryPos + 1) % 4);
	m_doors[2] = new Door(L"testNameMiddle", this, (entryPos + 2) % 4);
	m_doors[3] = new Door(L"testNameRight", this, (entryPos + 3) % 4);


	// Spawn an item
	Weapon* testItem = new Weapon("Axe.png");
	Weapon* testItem2 = new Weapon("Bow.png");

	SpawnItem(testItem, sf::Vector2f(50,50));
	SpawnItem(testItem2, sf::Vector2f(450, 50));

}

void Room::ResetDoorColors(int doorEnteredArrayIndex)
{
	m_doors[doorEnteredArrayIndex]->m_doorShape.setFillColor(sf::Color::Blue);
	for (int i = 1; i < 4; i++)
	{
		m_doors[(doorEnteredArrayIndex + i) % 4]->m_doorShape.setFillColor(sf::Color::Green);
		if (m_doors[(doorEnteredArrayIndex + i) % 4]->m_locked)
		{
			m_doors[(doorEnteredArrayIndex + i) % 4]->m_doorShape.setFillColor(sf::Color::Red);
		}
	}
}

Room::~Room()
{
	for (int i = 1; i < 4; i++)
	{
		if (m_doors[i]->m_toRoom)
		{
			delete m_doors[i]->m_toRoom;
			m_doors[i]->m_toRoom = nullptr;
		}
		delete m_doors[i];
		m_doors[i] = nullptr;
	}

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
	if (m_doors[0])
	{
		if (!m_doors[0]->m_fromRoom)
		{
			delete m_doors[0];
		}
		m_doors[0] = nullptr;
	}
}

void Room::CheckItemPickUp(Player * player)
{
	ItemEntity* closestItem = nullptr;
	float minDist = -1;
	int Itemindex = -1;
	float dist;

	for (int i = 0; i < m_itemsInRoom.size(); i++)
	{
		sf::Vector2f distVec = player->GetPosition() - m_itemsInRoom.at(i)->GetPosition();

		dist = sqrt(pow(distVec.x, 2) - pow(distVec.y, 2));
		if (dist < 50 && (dist < minDist || Itemindex == -1)) {
			closestItem = m_itemsInRoom.at(i);
			Itemindex = i;
			minDist = dist;
		}
	}

	if (closestItem != nullptr) {
		if (player->GiveItem(closestItem->GetItem())) {
			m_itemsInRoom.erase(m_itemsInRoom.begin() + Itemindex);
		}
	}
}


void Room::SpawnItem(Item* item, sf::Vector2f pos)
{
	// TODO: make these values random within the boundries of the room
	ItemEntity* newItem = new ItemEntity(item);
	newItem->SetPosition(pos);

	m_itemsInRoom.push_back(newItem);
}


std::wstring Room::GetRoomName() const
{
	return m_doors[0]->m_name;
}

int Room::GetDoorArrayIndex(int doorPositionIndex) const
{
	// Note: % is not modulus but the remainer which means it can have a negative value. Hence + 4
	return (doorPositionIndex - m_doors[0]->m_doorPositionIndex + 4) % 4;
}

Door* Room::GetDoor(int doorPositionIndex) const
{
	int doorArrayIndex = GetDoorArrayIndex(doorPositionIndex);
	//std::cout << "DOOR ARRAY INDEX:" << doorArrayIndex << std::endl;
	//std::cout << "DOOR POSITION INDEX:" << doorPositionIndex << std::endl;

	return m_doors[doorArrayIndex];
}

void Room::Update()
{
	m_enemyHandler->Update();
	m_fightHandler->Update();
}

void Room::StartFightInRoom(PlayerHandler* ph)
{
	for (unsigned int i = 0; i < m_enemyHandler->GetNrOfEnemies(); i++)
	{
		m_fightHandler->StartFight(ph->GetPlayer(), m_enemyHandler->GetEnemy(i));
	}
}

// ------------------ Private -------------------

void Room::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//TODO: Move to constructor since this does not need to be redone on every render
	sf::RectangleShape roomShape;
	roomShape.setSize(sf::Vector2f(WINDOW_WIDTH*0.9f, WINDOW_HEIGHT*0.9f));
	roomShape.setFillColor(m_roomColor);
	roomShape.setOutlineThickness(5.0f);
	roomShape.setOutlineColor(m_roomOutlineColor);
	roomShape.setOrigin(sf::Vector2f(WINDOW_WIDTH*0.45f, WINDOW_HEIGHT*0.45f));
	roomShape.setPosition(sf::Vector2f(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f));

	target.draw(roomShape, states);

	for (int i = 0; i < 4; i++)
	{
		if (m_doors[i])
		{
			target.draw(*m_doors[i], states);
		}
	}

	target.draw(*m_enemyHandler, states);

	/*Draw Items*/
	for (int i = 0; i < m_itemsInRoom.size(); i++)
	{
		target.draw(*m_itemsInRoom.at(i), states);
	}

}
