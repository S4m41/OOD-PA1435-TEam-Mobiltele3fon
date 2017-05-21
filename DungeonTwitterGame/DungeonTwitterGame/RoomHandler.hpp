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
	RoomHandler();
	~RoomHandler();

	bool EnterRoom(int doorPositionIndex);
	Room* GetCurrentRoom() const;

	void SetInput(Input* input);
	void Update();

	// Maybe not needed
	Player* GetPlayer();
	void CheckItemPickUp(Player* player);

private:
	Room* m_root;
	Room* m_currentRoom;

	PlayerHandler* m_playerHandler;

	void DisplayDoorLockedMessage() const;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // !ROOMHANDLER_HPP