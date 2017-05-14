#include "Enemy.hpp"
#include <SFML\Graphics\Color.hpp>

Enemy::Enemy() : Character(sf::Color::Red)
{
	SetWalkingSpeed(1.0f);
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	Character::Update();
}