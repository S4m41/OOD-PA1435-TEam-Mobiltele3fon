#ifndef ITEMENTITY_HPP
#define ITEMENTITY_HPP
#include "Entity.hpp"

class Item;

class ItemEntity : public Entity
{
public:
	ItemEntity(Item* item);
	~ItemEntity();
	void Update() {};
protected:
	Item* m_containedItem = nullptr;

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
#endif


