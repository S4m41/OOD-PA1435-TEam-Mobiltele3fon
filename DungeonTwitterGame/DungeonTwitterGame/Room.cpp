#include "Room.hpp"
#include "Item.hpp"

#include "ItemEntity.hpp"
#include <SFML\Graphics\Color.hpp>

Room::Room(std::wstring seedName) : Room(new Door(seedName, nullptr))
{

}

//TODO: Get items and doors from Twitter
//		Will just be random in the first iteration
Room::Room(Door* door)
{
	door->toRoom = this;
	m_entryDoor = door;

	//Get the names of the other doors in the room
	m_rightDoor = new Door(L"testNameRight", this);
	m_middleDoor = new Door(L"testNameMiddle", this);

	// leftDoor is a nullptr (aka locked) for the sake of testing
	//Door leftDoor = Door(L"testNameLeft", this);

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
	return m_entryDoor->name;
}



// ------------------ Private -------------------

