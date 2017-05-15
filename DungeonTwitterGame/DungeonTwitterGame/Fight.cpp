#include "Fight.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

Fight::Fight(Player* player, Enemy* enemy)
{
	m_player = player;
	m_enemy = enemy;
}

Fight::~Fight()
{
}

void Fight::Update()
{
	/*
	.
	.
	.
	. Control Enemy here
	.
	.*/


	m_enemy->SetMovement(m_player->GetPosition() - m_enemy->GetPosition());

	sf::Vector2f playerToEnemy = m_enemy->GetPosition() - m_player->GetPosition();
	float distance = std::sqrtf(playerToEnemy.x * playerToEnemy.x + playerToEnemy.y * playerToEnemy.y);

	if (distance < m_enemy->GetRadius() + m_player->GetRadius())
	{
		m_player->ChangeHealth(-1);
	}
}