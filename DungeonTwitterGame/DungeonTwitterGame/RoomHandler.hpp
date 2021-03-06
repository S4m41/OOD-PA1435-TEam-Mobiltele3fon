#ifndef ROOMHANDLER_HPP
#define ROOMHANDLER_HPP

#include "Room.hpp"
#include <SFML\Graphics\Drawable.hpp>
#include <string>

struct Door;
class Room;
class Input;
class PlayerHandler;
class Player;

class RoomHandler : public sf::Drawable
{
public:
	RoomHandler(std::wstring seedName = L"seed");
	~RoomHandler();

	bool EnterRoom(int doorPositionIndex);
	Room* GetCurrentRoom() const;

	void SetInput(Input* input);
	void Update();

	// Maybe not needed
	Player* GetPlayer();
	void CheckItemPickUp(Player* player);

private:
	bool TestDoor(Door* door) const;
	void DisplayDoorLockedMessage() const;

	Room* m_root;
	Room* m_currentRoom;

	PlayerHandler* m_playerHandler;


	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // !ROOMHANDLER_HPP
