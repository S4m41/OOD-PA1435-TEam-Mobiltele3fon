#include "Enemy.hpp"
#include <SFML\Graphics\Color.hpp>

Enemy::Enemy(float speed) : Character(sf::Color::Blue,speed)
{
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	Character::Update();
}