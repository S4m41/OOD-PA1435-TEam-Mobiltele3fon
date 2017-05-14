#include "RoomHandler.hpp"

// ------ public ---------

RoomHandler::RoomHandler(std::wstring seedName)
{
	m_currentRoom = m_root = new Room(seedName);
}

//TODO: Recursively delete all Rooms and doors
RoomHandler::~RoomHandler()
{

}

//TODO: Implement a way to select a door
//TODO: Update player position and comment
void RoomHandler::EnterRoom(Door* door)
{
	if (TestDoor(door)) 
	{
		if (door->fromRoom == m_currentRoom)
		{
			if (door->toRoom == nullptr) {
				door->toRoom = new Room(door);
			}
			m_currentRoom = door->toRoom;
		}
		else
		{
			m_currentRoom = door->fromRoom;
		}


		//TODO: Update player position. 
		//Might make this function return a bool and move the player in another class.
	}
	else 
	{
		DisplayDoorLockedMessage();
	}
}

Room* RoomHandler::GetCurrentRoom() const
{
	return m_currentRoom;
}

// -------- Private -----------

// 'Should' be done
bool RoomHandler::TestDoor(Door* door) const
{
	if (door->fromRoom == m_currentRoom)
	{
		return (!door->locked);
	}
	else 
	{
		return (door->fromRoom != nullptr);
	}
}

void RoomHandler::DisplayDoorLockedMessage() const
{

}