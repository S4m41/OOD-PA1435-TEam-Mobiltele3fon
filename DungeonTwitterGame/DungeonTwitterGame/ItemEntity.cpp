#include "ItemEntity.hpp"
#include "Item.hpp"
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>

ItemEntity::ItemEntity(Item* item) : Entity()
{
	m_containedItem = item;

	m_texture = new sf::Texture;
	m_texture->loadFromFile("Assets/Chest.png");
	m_sprite = new sf::Sprite(*m_texture);

	m_sprite->setOrigin(m_sprite->getTextureRect().width * 0.5f, m_sprite->getTextureRect().height*0.5);
	m_sprite->setScale(0.2f, 0.2f);
}

ItemEntity::~ItemEntity()
{
	if (m_texture)
	{
		delete m_texture;
		m_texture = nullptr;
	}
	if (m_sprite)
	{
		delete m_sprite;
		m_sprite = nullptr;
	}
}

void ItemEntity::SetPosition(sf::Vector2f position)
{
	Entity::SetPosition(position);
	m_sprite->setPosition(position);
}

Item* ItemEntity::GetItem()
{
	return m_containedItem;
}

float ItemEntity::GetWidth() const
{
	return m_sprite->getTextureRect().width * m_sprite->getScale().x;
}

float ItemEntity::GetHeight() const
{
	return m_sprite->getTextureRect().height * m_sprite->getScale().y;
}

float ItemEntity::GetRadius() const
{
	float w = m_sprite->getTextureRect().width * m_sprite->getScale().x * 0.5;
	float h = m_sprite->getTextureRect().height * m_sprite->getScale().y * 0.5;
	return std::sqrtf(w * w + h * h);
}

void ItemEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*m_sprite, states);
}