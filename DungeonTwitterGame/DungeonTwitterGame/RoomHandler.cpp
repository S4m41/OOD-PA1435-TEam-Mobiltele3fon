#include "RoomHandler.hpp"
#include "PlayerHandler.hpp"
#include "Room.hpp"

#include <SFML\Window\Keyboard.hpp>
#include "Player.hpp"

#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>

#include <iostream>

// ------ public ---------

RoomHandler::RoomHandler(std::wstring seedName)
{
	m_currentRoom = m_root = new Room(seedName);

	m_playerHandler = new PlayerHandler;
	m_playerHandler->CreatePlayer();

	m_currentRoom->StartFightInRoom(m_playerHandler);
}

RoomHandler::~RoomHandler()
{
	if (m_playerHandler)
	{
		delete m_playerHandler;
		m_playerHandler = nullptr;
	}
	if (m_root)
	{
		delete m_root;
		m_root = nullptr;
		m_currentRoom = nullptr;
	}
}

//TODO: comment
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
				door->m_toRoom->StartFightInRoom(m_playerHandler);
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

Player * RoomHandler::GetPlayer()
{
	return m_playerHandler->GetPlayer();
}

void RoomHandler::CheckItemPickUp(Player * player)
{
	m_currentRoom->CheckItemPickUp(player);
}

// -------- Private -----------

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
	target.draw(*m_playerHandler, states);
}

void RoomHandler::SetInput(Input* input)
{
	m_playerHandler->SetInput(input);
}

void RoomHandler::Update()
{
	m_playerHandler->Update();
	m_currentRoom->Update();
}