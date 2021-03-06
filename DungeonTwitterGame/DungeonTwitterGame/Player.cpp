#include "Player.hpp"
#include <SFML\Graphics\Color.hpp>

Player::Player(bool isRanged) : Character(sf::Color::Cyan,1, isRanged)
{
	m_moveUp = m_moveDown = m_moveRight = m_moveLeft = false;
	m_position = sf::Vector2f(200.0f, 200.0f);
}
Player::~Player()
{
}

void Player::Update()
{
	SetMovement(sf::Vector2f(float(m_moveRight - m_moveLeft), float(m_moveDown - m_moveUp)));
	Character::Update();

	// Reset movement
	m_moveUp = m_moveDown = m_moveRight = m_moveLeft = false;
}

void Player::SetMoveUp()
{
	m_moveUp = true;
}
void Player::SetMoveDown()
{
	m_moveDown = true;
}
void Player::SetMoveRight()
{
	m_moveRight = true;
}
void Player::SetMoveLeft()
{
	m_moveLeft = true;
}