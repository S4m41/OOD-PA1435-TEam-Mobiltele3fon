#ifndef ROOMHANDLER_HPP
#define ROOMHANDLER_HPP

#include "Room.hpp"

class RoomHandler
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
};

#endif // !ROOMHANDLER_HPP
