#ifndef ROOM_HPP
#define ROOM_HPP

#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\Color.hpp>


#include <string>
#include <vector>

class Room;

class Item;
class ItemEntity;

struct Door //: sf::Drawable
{
	std::wstring name = L" ";
	Room* fromRoom = nullptr;
	Room* toRoom = nullptr;
	bool locked = true;

	Door(std::wstring n, Room* from) : name(n), fromRoom(from), locked(from != nullptr) {}

	//void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

class Room : public sf::Drawable
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

	const sf::Color m_roomColor = sf::Color::Color(140, 54, 1);
	const sf::Color m_roomOutlineColor = sf::Color::Color(255, 255, 255);


	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};




#endif // !ROOM_HPP