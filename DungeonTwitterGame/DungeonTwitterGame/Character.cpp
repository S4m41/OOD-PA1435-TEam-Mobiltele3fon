#include "Character.hpp"

#include <SFML\Graphics\Color.hpp>

Character::Character(sf::Color color) : Entity(color)
{
	m_position = sf::Vector2f(200.0f, 200.0f);
	m_movement = sf::Vector2f(0.0f, 0.0f);
	m_walkingSpeed = 5.0f;
	m_health = 100;
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