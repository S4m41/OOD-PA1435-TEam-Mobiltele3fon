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
	Room* toRoom = nullptr;
	bool locked = true;

	Door(std::wstring n, Room* from) : name(n), fromRoom(from), locked(from != nullptr) {}
};

struct RoomItem
{
	Item item;
	int x_location;
	int y_location;

	RoomItem(Item i, int x = 0, int y = 0) : item(i), x_location(x), y_location(y) {}
};

class Room
{
public:
	Room(std::wstring seedName);
	Room(Door* door);
	~Room();

	void SpawnItem(Item item);

	bool IsLegal(/*position*/) const;

	std::wstring GetRoomName() const;
private:
	Door* m_entryDoor = nullptr;
	Door* m_leftDoor = nullptr;
	Door* m_middleDoor = nullptr;
	Door* m_rightDoor = nullptr;

	std::vector<RoomItem> m_itemsInRoom;

};




#endif // !ROOM_HPP