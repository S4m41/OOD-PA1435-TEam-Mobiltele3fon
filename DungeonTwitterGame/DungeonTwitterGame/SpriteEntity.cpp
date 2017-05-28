#include "SpriteEntity.hpp"
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <string>

SpriteEntity::SpriteEntity(char* textureName) : Entity()
{
	m_texture = new sf::Texture;
	m_texture->loadFromFile("Assets/" + std::string(textureName));
	m_sprite = new sf::Sprite(*m_texture);
}

SpriteEntity::~SpriteEntity()
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

void SpriteEntity::SetPosition(sf::Vector2f position)
{
	Entity::SetPosition(position);
	m_sprite->setPosition(position);
}

sf::Sprite* SpriteEntity::GetSprite()
{
	return m_sprite;
}

void SpriteEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*m_sprite, states);
}