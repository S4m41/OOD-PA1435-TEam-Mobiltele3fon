#ifndef ROOM_HPP
#define ROOM_HPP

#include "Item.hpp"
#include <string>
#include <vector>

class Room;

struct Door
{
	std::wstring name = L" ";
	Room* fromRoom = nullptr;
	Room* toRoom   = nullptr;
};

struct RoomItem
{
	Item item;
	int x_location;
	int y_location;
};

class Room
{
public:
	Room();
	Room(Door* door);
	~Room();

	void SpawnItem(Item item);

	bool IsLegal(/*position*/) const;
	
	std::wstring GetRoomName() const;
	Room CreateRoom(Door* door) const;		//should probably be a pointer
	bool TestDoor(Door* door) const;
	void EnterRoom(Door* door) const;
	
private:
	Door* leftDoor = nullptr;
	Door* middleDoor = nullptr;
	Door* rightDoor = nullptr;

	Room* parent;

	std::wstring m_roomName;
	std::vector<RoomItem> m_itemsInRoom;

	void DisplayDoorLockedMessage() const;

};




#endif // !ROOM_HPP
