#ifndef ROOM_HPP
#define ROOM_HPP

#include "SystemSettings.hpp"
#include <SFML\Graphics\Drawable.hpp>
#include <vector>

namespace DoorPosition
{
	static const sf::Vector2f DOOR_POS_LEFT   = sf::Vector2f(256.0f, 256.0f) + WINDOW_WIDTH*0.45f * sf::Vector2f(-1.0f, 0.0f);
	static const sf::Vector2f DOOR_POS_RIGHT  = sf::Vector2f(256.0f, 256.0f) + WINDOW_WIDTH*0.45f * sf::Vector2f(1.0f, 0.0f);
	static const sf::Vector2f DOOR_POS_TOP    = sf::Vector2f(256.0f, 256.0f) + WINDOW_WIDTH*0.45f * sf::Vector2f(0.0f, -1.0f);
	static const sf::Vector2f DOOR_POS_BOTTOM = sf::Vector2f(256.0f, 256.0f) + WINDOW_WIDTH*0.45f * sf::Vector2f(0.0f, 1.0f);
}

static const sf::Vector2f DoorPositionArray[4] = 
{
	DoorPosition::DOOR_POS_TOP,
	DoorPosition::DOOR_POS_RIGHT,
	DoorPosition::DOOR_POS_BOTTOM,
	DoorPosition::DOOR_POS_LEFT
};

namespace sf
{
	class RectangleShape;
}

class Item;
class ItemEntity;
class EnemyHandler;
class FightHandler;
class Player;

class Room : public sf::Drawable
{
public:
	Room();
	Room(Room* parent, int parentLocation);
	~Room();

	bool CreateNeighboringRoom(int location);
	Room* GetNeighboringRoom(int location);
	bool IsNeighboringRoomLocked(int location);

	void Update();

	void StartFightInRoom(Player* player);

	void SpawnItem(Item* item, sf::Vector2f pos);
	void CheckItemPickUp(Player* player);

private:
	std::vector<ItemEntity*> m_itemsInRoom;

	EnemyHandler* m_enemyHandler;
	FightHandler* m_fightHandler;

	struct Neighbor
	{
		Room* room = nullptr;
		bool locked = false;
	};

	Neighbor m_neighboringRoom[4];
	int m_entryPoint;

	sf::RectangleShape* m_roomShape;
	sf::RectangleShape* m_doors[4];

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // !ROOM_HPP