#ifndef ITEMENTITY_HPP
#define ITEMENTITY_HPP
#include "Entity.hpp"

class Item;

class ItemEntity : public Entity
{
public:
	ItemEntity(sf::Color color, Item* item);
	~ItemEntity();
	void Update() {};
protected:
	Item* m_containedItem;
};
#endif


