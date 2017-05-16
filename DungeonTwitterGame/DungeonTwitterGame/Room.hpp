#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include <vector>

class Room;

class Item;
class ItemEntity;

struct Door
{
	std::wstring name = L" ";
	Room* fromRoom = nullptr;
	Room* toRoom = nullptr;
	bool locked = true;

	Door(std::wstring n, Room* from) : name(n), fromRoom(from), locked(from != nullptr) {}
};

class Room
{
public:
	Room(std::wstring seedName);
	Room(Door* door);
	~Room();

	void SpawnItem(Item* item);

	bool IsLegal(/*position*/) const;

	std::wstring GetRoomName() const;
private:
	Door* m_entryDoor = nullptr;
	Door* m_leftDoor = nullptr;
	Door* m_middleDoor = nullptr;
	Door* m_rightDoor = nullptr;

	std::vector<ItemEntity> m_itemsInRoom;

};




#endif // !ROOM_HPP