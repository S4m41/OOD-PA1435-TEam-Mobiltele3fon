//TODO: remove includes of headers that are already used in Room.hpp
#include "Room.hpp"
#include "Item.hpp"

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
	//Move the entry door to the other side of the room
	unsigned int entryPos = door->m_doorPositionIndex = (door->m_doorPositionIndex + 2) % 4;
	door->m_toRoom = this;
	m_entryDoor = door;

	//Get the names of the other doors in the room

	// leftDoor is a nullptr (aka m_locked) for the sake of testing
	//Door leftDoor = Door(L"testNameLeft", this, (entryPos + 1) % 4);
	m_middleDoor = new Door(L"testNameMiddle", this, (entryPos + 2) % 4);
	m_rightDoor = new Door(L"testNameRight", this, (entryPos + 3) % 4);

	//m_leftDoor = &leftDoor;
	/*m_middleDoor = &middleDoor;
	m_rightDoor = &rightDoor;*/

	// Spawn an item
	Item testItem;
	SpawnItem(&testItem);
}

// TODO: Recursively delete the entire tree of rooms
Room::~Room()
{

}


void Room::SpawnItem(Item* item)
{
	// TODO: make these values random within the boundries of the room
	int xLocation = 0;
	int yLocation = 0;
	ItemEntity newItem = ItemEntity(sf::Color::Cyan, item);
	newItem.SetPosition(sf::Vector2f(xLocation, yLocation));

	m_itemsInRoom.push_back(newItem);
}

// TODO
bool Room::IsLegal() const
{
	bool legal = true;

	return legal;
}

std::wstring Room::GetRoomName() const
{
	return m_entryDoor->m_name;
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

	if (m_entryDoor)
	{
		target.draw(*m_entryDoor, states);
	}
	if (m_leftDoor)
	{
		target.draw(*m_leftDoor, states);
	}
	if (m_middleDoor)
	{
		target.draw(*m_middleDoor, states);
	}
	if (m_rightDoor)
	{
		target.draw(*m_rightDoor, states);
	}
}
