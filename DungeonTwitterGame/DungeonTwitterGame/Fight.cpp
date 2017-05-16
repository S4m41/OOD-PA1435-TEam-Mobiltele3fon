#include "Fight.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Weapon.hpp"

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

	sf::Vector2f playerToEnemy = m_enemy->GetPosition() - m_player->GetPosition();

	float distance = std::sqrtf(playerToEnemy.x * playerToEnemy.x + playerToEnemy.y * playerToEnemy.y);

	if (distance > m_player->GetRadius() + m_enemy->GetRadius() && m_enemy->GetHealth()>0)
	{

		m_enemy->SetMovement(m_player->GetPosition() - m_enemy->GetPosition());

		playerToEnemy = m_enemy->GetPosition() - m_player->GetPosition();

		distance = std::sqrtf(playerToEnemy.x * playerToEnemy.x + playerToEnemy.y * playerToEnemy.y);

	}
	  
	if (m_player->GetActiveWeapon()) {
		if (m_enemy->GetHealth()>0 && distance < m_enemy->GetRadius() + m_player->GetRadius() + m_player->GetActiveWeapon()->GetRange() && m_player->Attack())
		{
			m_enemy->ChangeHealth(-(m_player->GetActiveWeapon()->GetDamage()));
		}
	}
	if (m_enemy->GetActiveWeapon()) {
		if (m_player->GetHealth()>0 && distance < m_enemy->GetRadius() + m_player->GetRadius() + m_enemy->GetActiveWeapon()->GetRange() && m_enemy->Attack())
		{
			m_player->ChangeHealth(-(m_enemy->GetActiveWeapon()->GetDamage()));
		}
	}
}