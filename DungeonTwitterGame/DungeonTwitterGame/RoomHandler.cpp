#include "PlayerHandler.hpp"
#include "EnemyHandler.hpp"
#include "FightHandler.hpp"
#include "RoomHandler.hpp"
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>

// ------ public ---------

RoomHandler::RoomHandler(std::wstring seedName)
{
	m_currentRoom = m_root = new Room(seedName);

	// New
	m_playerHandler = new PlayerHandler;
	//m_enemyHandler = new EnemyHandler;
	m_fightHandler = new FightHandler;

	m_playerHandler->CreatePlayer();

	/*for (int i = 0; i < 5; i++)
	{
		m_enemyHandler->CreateEnemy();
	}
*/
	for (unsigned int i = 0; i < m_currentRoom->GetNrOfEnemiesInRoom(); i++)
	{
		m_fightHandler->StartFight(m_playerHandler->GetPlayer(), m_currentRoom->GetEnemyInRoom(i));
	}
}

//TODO: Recursively delete all Rooms and doors
RoomHandler::~RoomHandler()
{
	if (m_playerHandler)
	{
		delete m_playerHandler;
		m_playerHandler = nullptr;
	}
	/*if (m_enemyHandler)
	{
		delete m_enemyHandler;
		m_enemyHandler = nullptr;
	}*/
	if (m_fightHandler)
	{
		delete m_fightHandler;
		m_fightHandler = nullptr;
	}

	//TODO: Remove Rooms and stuff
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
	//target.draw(*m_enemyHandler, states);
	target.draw(*m_playerHandler, states);
}


// New functions as of room-v2.1

void RoomHandler::SetInput(Input* input)
{
	m_playerHandler->SetInput(input);
}

void RoomHandler::Update()
{
	m_playerHandler->Update();
	m_fightHandler->Update();
	m_currentRoom->Update();
	//m_enemyHandler->Update();
}

sf::Vector2f RoomHandler::GetPlayerPosition() const
{
	return m_playerHandler->GetPlayerPosition();
}
//
void RoomHandler::SetPlayerPosition(sf::Vector2f position)
{
	m_playerHandler->SetPlayerPosition(position);
}