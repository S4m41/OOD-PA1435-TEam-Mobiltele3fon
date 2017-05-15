#include "ItemEntity.hpp"
#include <SFML\Graphics\Color.hpp>

ItemEntity::ItemEntity(sf::Color color, Item* item) : Entity(color)
{
	m_containedItem = item;
}

ItemEntity::~ItemEntity()
{

}
