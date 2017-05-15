#ifndef ROOMHANDLER_HPP
#define ROOMHANDLER_HPP

#include "Room.hpp"
#include <SFML\Graphics\Drawable.hpp>


class RoomHandler : public sf::Drawable
{
public:
	RoomHandler(std::wstring seedName = L"seed");
	~RoomHandler();

	void EnterRoom(Door* door);
	Room* GetCurrentRoom() const;
private:
	bool TestDoor(Door* door) const;
	void DisplayDoorLockedMessage() const;

	Room* m_root;
	Room* m_currentRoom;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // !ROOMHANDLER_HPP
