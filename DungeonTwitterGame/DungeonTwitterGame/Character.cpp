#include "Character.hpp"
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\Graphics\CircleShape.hpp>
#include <SFML\Graphics\Color.hpp>

Character::Character()
{
	m_health = 100;
	m_walkingSpeed = 1;
	m_position = sf::Vector2f(200, 200);
	m_moveUp = m_moveDown = m_moveRight = m_moveLeft = false;
}
Character::~Character()
{
}

void Character::Update()
{
	sf::Vector2f move = sf::Vector2f(m_moveRight - m_moveLeft, m_moveDown - m_moveUp) * m_walkingSpeed;
	m_position += move;
	m_moveUp = m_moveDown = m_moveRight = m_moveLeft = false;
}

void Character::SetPosition(sf::Vector2f position)
{
	m_position = position;
}
sf::Vector2f Character::GetPosition() const
{
	return m_position;
}

void Character::SetMoveUp()
{
	m_moveUp = true;
}
void Character::SetMoveDown()
{
	m_moveDown = true;
}
void Character::SetMoveRight()
{
	m_moveRight = true;
}
void Character::SetMoveLeft()
{
	m_moveLeft = true;
}

void Character::SetHealth(int health)
{
	m_health = health;
}
int Character::GetHealth() const
{
	return m_health;
}

void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape circle(50.0f);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(m_position);
	target.draw(circle, states);
}