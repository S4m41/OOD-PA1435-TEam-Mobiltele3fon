#include "Entity.hpp"
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\Graphics\CircleShape.hpp>


Entity::Entity(sf::Color color, float size)
{
	m_color = new sf::Color(color);
	m_size = size;
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

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape circle(m_size);
	circle.setFillColor(*m_color);
	circle.setPosition(m_position);
	target.draw(circle, states);
}