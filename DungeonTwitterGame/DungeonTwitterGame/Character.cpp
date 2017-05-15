#include "Character.hpp"
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\Graphics\CircleShape.hpp>
#include <SFML\Graphics\Color.hpp>

Character::Character(sf::Color color)
{
	m_position = sf::Vector2f(200.0f, 200.0f);
	m_movement = sf::Vector2f(0.0f, 0.0f);
	m_walkingSpeed = 5.0f;
	m_health = 100;
	m_color = new sf::Color(color);
}
Character::~Character()
{
	if (m_color)
	{
		delete m_color;
		m_color = nullptr;
	}
}

void Character::Update()
{
	sf::Vector2f move = m_movement * m_walkingSpeed;

	m_position += move;

	// Reset movement
	m_movement = sf::Vector2f(0.0f, 0.0f);
}

void Character::SetPosition(sf::Vector2f position)
{
	m_position = position;
}
sf::Vector2f Character::GetPosition() const
{
	return m_position;
}

void Character::SetMovement(sf::Vector2f movement)
{
	m_movement = movement;
	float length = std::sqrtf(movement.x * movement.x + movement.y * movement.y);
	m_movement *= length > 0 ? 1 / length : 0;			// Normalize movement
}

sf::Vector2f Character::GetMovement() const
{
	return m_movement;
}

void Character::SetWalkingSpeed(float speed)
{
	m_walkingSpeed = std::fmaxf(0.5f, speed);
}

float Character::GetWalkingSpeed() const
{
	return m_walkingSpeed;
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
	sf::CircleShape circle(20.0f);
	circle.setFillColor(*m_color);
	circle.setPosition(m_position);
	target.draw(circle, states);
}