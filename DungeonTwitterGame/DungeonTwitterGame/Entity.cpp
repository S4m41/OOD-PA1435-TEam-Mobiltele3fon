#include "Entity.hpp"
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\Graphics\CircleShape.hpp>


Entity::Entity(sf::Color color, float size)
{
	m_color = new sf::Color(color);
	m_radius = size;
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

float Entity::GetRadius() const
{
	return m_radius;
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape circle(m_radius);
	circle.setFillColor(*m_color);
	circle.setPosition(m_position);
	circle.setOrigin(sf::Vector2f(m_radius, m_radius));
	target.draw(circle, states);
}