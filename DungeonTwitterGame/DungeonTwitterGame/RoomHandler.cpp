#include "RoomHandler.hpp"
#include "Room.hpp"
#include "PlayerHandler.hpp"
#include "Player.hpp"

#include <SFML\Window\Keyboard.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>

#include <iostream>

RoomHandler::RoomHandler()
{
	m_currentRoom = m_root = new Room;

	m_playerHandler = new PlayerHandler;
	m_playerHandler->CreatePlayer();

	m_currentRoom->StartFightInRoom(m_playerHandler->GetPlayer());
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
//void RoomHandler::SetInput(Input* input)
//{
//	m_playerHandler->SetInput(input);
//}

void RoomHandler::Update()
{
	m_playerHandler->Update();
	m_currentRoom->Update();
}

bool RoomHandler::EnterRoom(int doorPositionIndex)
{
	if (!m_currentRoom->CreateNeighboringRoom(doorPositionIndex))
	{
		// Locked, or invalid index
		DisplayDoorLockedMessage();
		return false;
	}

	// Neighbor guaranteed not to be a nullptr
	m_currentRoom = m_currentRoom->GetNeighboringRoom(doorPositionIndex);
	m_currentRoom->StartFightInRoom(m_playerHandler->GetPlayer());

	return true;
}
Room* RoomHandler::GetCurrentRoom() const
{
	return m_currentRoom;
}
Player* RoomHandler::GetPlayer()
{
	return m_playerHandler->GetPlayer();
}

void RoomHandler::CheckItemPickUp(Player* player)
{
	m_currentRoom->CheckItemPickUp(player);
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