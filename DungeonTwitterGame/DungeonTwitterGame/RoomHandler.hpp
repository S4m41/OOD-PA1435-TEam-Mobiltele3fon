#ifndef ROOMHANDLER_HPP
#define ROOMHANDLER_HPP

#include "Room.hpp"
#include <SFML\Graphics\Drawable.hpp>

class Player;

class RoomHandler : public sf::Drawable
{
public:
	RoomHandler(std::wstring seedName = L"seed");
	~RoomHandler();

	bool EnterRoom(int doorPositionIndex);
	Room* GetCurrentRoom() const;
	void CheckItemPickUp(Player* player);

private:
	bool TestDoor(Door* door) const;
	void DisplayDoorLockedMessage() const;

	Room* m_root;
	Room* m_currentRoom;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // !ROOMHANDLER_HPP
