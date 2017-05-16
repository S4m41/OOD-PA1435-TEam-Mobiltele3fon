#ifndef ROOM_HPP
#define ROOM_HPP

#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include "SystemSettings.hpp"
#include <string>

namespace DoorPosition
{
	static const sf::Vector2f DOOR_POS_LEFT   = sf::Vector2f(256.0f, 256.0f) + WINDOW_WIDTH*0.45f * sf::Vector2f(-1.0f, 0.0f);
	static const sf::Vector2f DOOR_POS_RIGHT  = sf::Vector2f(256.0f, 256.0f) + WINDOW_WIDTH*0.45f * sf::Vector2f(1.0f, 0.0f);
	static const sf::Vector2f DOOR_POS_TOP    = sf::Vector2f(256.0f, 256.0f) + WINDOW_WIDTH*0.45f * sf::Vector2f(0.0f, -1.0f);
	static const sf::Vector2f DOOR_POS_BOTTOM = sf::Vector2f(256.0f, 256.0f) + WINDOW_WIDTH*0.45f * sf::Vector2f(0.0f, 1.0f);
}

static const sf::Vector2f DoorPositionArray[4] = 
{ 
	DoorPosition::DOOR_POS_BOTTOM,
	DoorPosition::DOOR_POS_LEFT,
	DoorPosition::DOOR_POS_TOP,
	DoorPosition::DOOR_POS_RIGHT 
};

class Enemy;
class Room;
class Item;
class ItemEntity;

class EnemyHandler;
class FightHandler;
class PlayerHandler;

struct Door : public sf::Drawable
{
	std::wstring m_name = L" ";
	Room* m_fromRoom = nullptr;
	Room* m_toRoom = nullptr;
	bool m_locked = true;
	int m_doorPositionIndex;

	sf::RectangleShape m_doorShape;

	Door(std::wstring n, Room* from, int pos_ind = 0) 
		: m_name(n), m_fromRoom(from), m_locked(!(from != nullptr && m_name != L" ")), m_doorPositionIndex(pos_ind) 
	{
		m_doorShape.setSize(sf::Vector2f(80, 10));
		if (!m_locked)
		{
			m_doorShape.setFillColor(sf::Color::Green);
		}
		else
		{
			m_doorShape.setFillColor(sf::Color::Red);
		}
		m_doorShape.setOutlineThickness(0.0f);
		m_doorShape.setOrigin(sf::Vector2f(40, 4));
		m_doorShape.rotate(90 * m_doorPositionIndex);
		m_doorShape.setPosition(DoorPositionArray[m_doorPositionIndex]);
	}


	void MoveDoorToOppositeWall()
	{
		m_doorPositionIndex = (m_doorPositionIndex + 2) % 4;
		m_doorShape.rotate(180);
		m_doorShape.setPosition(DoorPositionArray[m_doorPositionIndex]);
	}


	void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		target.draw(m_doorShape, states);
	}
};

class Player;

class Room : public sf::Drawable
{
public:
	Room(std::wstring seedName);
	Room(Door* door);
	~Room();

	void SpawnItem(Item* item, sf::Vector2f pos);

	void Update();

	void StartFightInRoom(PlayerHandler* ph);

	std::wstring GetRoomName() const;
	int Room::GetDoorArrayIndex(int doorPositionIndex) const;
	Door* GetDoor(int doorPositionIndex) const;
	void ResetDoorColors(int doorEnteredArrayIndex);
	void CheckItemPickUp(Player* player);

private:
	// 0: Entry, 1: left, 2: opposite, 3: right
	Door* m_doors[4] = { nullptr };

	std::vector<ItemEntity*> m_itemsInRoom;

	EnemyHandler* m_enemyHandler;
	FightHandler* m_fightHandler;

	const sf::Color m_roomColor = sf::Color::Color(140, 54, 1);
	const sf::Color m_roomOutlineColor = sf::Color::Color(255, 255, 255);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif // !ROOM_HPP