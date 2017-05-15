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
	. m_player->SetHealth() .... and so on
	.
	.*/

	m_enemy->SetMovement(m_player->GetPosition() - m_enemy->GetPosition());

}