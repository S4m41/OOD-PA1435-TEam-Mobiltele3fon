//TODO: remove includes of headers that are already used in Room.hpp
#include "Room.hpp"
//#include "Item.hpp"
#include "Weapon.hpp"
#include "Player.hpp"

#include "SystemSettings.hpp"
#include "ItemEntity.hpp"
#include <SFML\Graphics\RenderTarget.hpp>

#include <SFML\Graphics\Color.hpp>
#include <SFML\Graphics\RectangleShape.hpp>


Room::Room(std::wstring seedName) : Room(new Door(seedName, nullptr))
{

}

//TODO: Get items and doors from Twitter
//		Will just be random in the first iteration
Room::Room(Door* door)
{
	int entryPos = door->m_doorPositionIndex;

	door->m_toRoom = this;
	m_doors[0] = door;

	// leftDoor is a nullptr (aka m_locked) for the sake of testing
	// name = L" " == locked door
	m_doors[1] = new Door(L" ", this, (entryPos + 1) % 4);
	m_doors[2] = new Door(L"testNameMiddle", this, (entryPos + 2) % 4);
	m_doors[3] = new Door(L"testNameRight", this, (entryPos + 3) % 4);


	// Spawn an item
	Weapon testItem("Axe.png");
	SpawnItem(&testItem, sf::Vector2f(50,50));
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

void Room::CheckItemPickUp(Player * player)
{
	ItemEntity* closestItem = nullptr;
	float minDist = -1;
	int Itemindex = -1;
	float dist;

	for (int i = 0; i < m_itemsInRoom.size(); i++)
	{
		sf::Vector2f distVec = player->GetPosition() - m_itemsInRoom.at(i)->GetPosition();

		dist = sqrt(pow(distVec.x,2)- pow(distVec.y, 2));
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

// TODO: Recursively delete the entire tree of rooms
Room::~Room()
{
	while (!m_itemsInRoom.empty())
	{
		ItemEntity* item = m_itemsInRoom.at(0);
		m_itemsInRoom.pop_back();

		delete item;
	}
}


void Room::SpawnItem(Item* item, sf::Vector2f pos)
{
	// TODO: make these values random within the boundries of the room
	ItemEntity* newItem = new ItemEntity(item);
	newItem->SetPosition(pos);

	m_itemsInRoom.push_back(newItem);
}

// TODO: Remove
bool Room::IsLegal() const
{
	bool legal = true;

	return legal;
}

std::wstring Room::GetRoomName() const
{
	return m_doors[0]->m_name;
}

int Room::GetDoorArrayIndex(int doorPositionIndex) const
{
	// % is not modulus but the remainer which means it can have a negative value. Hence + 4
	return (doorPositionIndex - m_doors[0]->m_doorPositionIndex + 4) % 4;
}

Door* Room::GetDoor(int doorPositionIndex) const
{
	int doorArrayIndex = GetDoorArrayIndex(doorPositionIndex);
	//std::cout << "DOOR ARRAY INDEX:" << doorArrayIndex << std::endl;
	//std::cout << "DOOR POSITION INDEX:" << doorPositionIndex << std::endl;

	return m_doors[doorArrayIndex];
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

	/*Draw Items*/
	for (int i = 0; i < m_itemsInRoom.size(); i++)
	{
		target.draw(*m_itemsInRoom.at(i), states);
	}
}
