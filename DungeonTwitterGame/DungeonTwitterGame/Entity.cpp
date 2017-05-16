#include "Entity.hpp"
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\Graphics\CircleShape.hpp>


Entity::Entity()
{
	m_position = sf::Vector2f(0.0f, 0.0f);
}

Entity::~Entity()
{

}

void Entity::SetPosition(sf::Vector2f position)
{
	m_position = position;
}
sf::Vector2f Entity::GetPosition() const
{
	return m_position;
}
