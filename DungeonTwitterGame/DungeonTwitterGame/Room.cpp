#include "Room.hpp"

Room::Room()
{

}

Room::Room(Door* door)
{
	m_roomName = door->name;

	//TODO: Fill room with items
}

Room::~Room()
{

}

void Room::SpawnItem(Item item)
{

}

// TODO
bool Room::IsLegal() const
{
	bool legal = true;

	return legal;
}

std::wstring Room::GetRoomName() const
{
	return m_roomName;
}

Room Room::CreateRoom(Door* door) const
{
	Room newRoom(door);

}


bool Room::TestDoor(Door* door) const
{
	return (door != nullptr) ? true : false;
}

void Room::EnterRoom(Door* door) const
{

}

// ------------------ Private -------------------

void Room::DisplayDoorLockedMessage() const
{

}


