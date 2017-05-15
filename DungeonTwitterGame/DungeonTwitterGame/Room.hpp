#ifndef ROOM_HPP
#define ROOM_HPP

#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\Color.hpp>
#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\Graphics\RenderTarget.hpp>


#include <string>
#include <vector>
#include<iostream>

namespace DoorPosition
{
	static const sf::Vector2f DOOR_POS_LEFT   = sf::Vector2f(256.0f, 256.0f) + 150.0f * sf::Vector2f(-1.0f, 0.0f);
	static const sf::Vector2f DOOR_POS_RIGHT  = sf::Vector2f(256.0f, 256.0f) + 150.0f * sf::Vector2f(1.0f, 0.0f);
	static const sf::Vector2f DOOR_POS_TOP    = sf::Vector2f(256.0f, 256.0f) + 150.0f * sf::Vector2f(0.0f, -1.0f);
	static const sf::Vector2f DOOR_POS_BOTTOM = sf::Vector2f(256.0f, 256.0f) + 150.0f * sf::Vector2f(0.0f, 1.0f);
}

static const sf::Vector2f DoorPositionArray[4] = 
{ 
	DoorPosition::DOOR_POS_BOTTOM, 
	DoorPosition::DOOR_POS_LEFT,
	DoorPosition::DOOR_POS_TOP,
	DoorPosition::DOOR_POS_RIGHT 
};

class Room;
class Item;
class ItemEntity;


struct Door : public sf::Drawable
{
	std::wstring m_name = L" ";
	Room* m_fromRoom = nullptr;
	Room* m_toRoom = nullptr;
	bool m_locked = true;
	unsigned int m_doorPositionIndex;

	Door(std::wstring n, Room* from, unsigned int pos_ind = 2) 
		: m_name(n), m_fromRoom(from), m_locked(from != nullptr), m_doorPositionIndex(pos_ind) 
	{}

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		sf::RectangleShape doorShape;
		doorShape.setSize(sf::Vector2f(20, 40));
		doorShape.setFillColor(sf::Color::Blue);
		doorShape.setOutlineThickness(0.0f);
		doorShape.setOrigin(sf::Vector2f(10, 20));
		
		doorShape.setPosition(DoorPositionArray[m_doorPositionIndex]);

		target.draw(doorShape, states);
	}
};

class Room : public sf::Drawable
{
public:
	Room(std::wstring seedName);
	Room(Door* door);
	~Room();

	void SpawnItem(Item* item);

	bool IsLegal(/*m_position*/) const;

	std::wstring GetRoomName() const;
private:
	//TODO: Rename to avoid confusion with the position on the screen
	Door* m_entryDoor = nullptr;
	Door* m_leftDoor = nullptr;
	Door* m_middleDoor = nullptr;
	Door* m_rightDoor = nullptr;

	std::vector<ItemEntity> m_itemsInRoom;

	const sf::Color m_roomColor = sf::Color::Color(140, 54, 1);
	const sf::Color m_roomOutlineColor = sf::Color::Color(255, 255, 255);


	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};




#endif // !ROOM_HPP