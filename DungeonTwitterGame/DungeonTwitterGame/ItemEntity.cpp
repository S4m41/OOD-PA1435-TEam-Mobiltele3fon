#include "ItemEntity.hpp"
#include "Item.hpp"
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>

ItemEntity::ItemEntity(Item* item) : Entity()
{
	m_containedItem = item;
}

ItemEntity::~ItemEntity()
{

}

void ItemEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*m_containedItem, states);
}