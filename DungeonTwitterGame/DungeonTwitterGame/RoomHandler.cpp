#include "RoomHandler.hpp"
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>
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
//TODO: Update player m_position and comment
bool RoomHandler::EnterRoom(int doorPositionIndex)
{
	Door* door = m_currentRoom->GetDoor(doorPositionIndex);
	if (TestDoor(door)) 
	{
		door->MoveDoorToOppositeWall();
		if (door->m_fromRoom == m_currentRoom)
		{
			if (door->m_toRoom == nullptr) {
				door->m_toRoom = new Room(door);
			}
			m_currentRoom = door->m_toRoom;
		}
		else
		{
			m_currentRoom = door->m_fromRoom;
		}
		int doorArrayIndex = m_currentRoom->GetDoorArrayIndex((doorPositionIndex + 2) % 4);
		m_currentRoom->ResetDoorColors(doorArrayIndex);
		return true;
	}
	else 
	{
		DisplayDoorLockedMessage();
		return false;
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
	if (door->m_fromRoom == m_currentRoom)
	{
		return (!door->m_locked);
	}
	else 
	{
		return (door->m_fromRoom != nullptr);
	}
}

void RoomHandler::DisplayDoorLockedMessage() const
{
	std::cout << "DOOR IS LOCKED" << std::endl;
}

void RoomHandler::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_currentRoom)
	{
		target.draw(*m_currentRoom, states);
	}
}
