#include "FightHandler.hpp"
#include "Fight.hpp"

FightHandler::FightHandler()
{
}

FightHandler::~FightHandler()
{
	for (unsigned int i = 0; i < m_fights.size(); i++)
	{
		delete m_fights[i];
		m_fights[i] = nullptr;
	}
}

void FightHandler::StartFight(Player* player, Enemy* enemy)
{
	m_fights.push_back(new Fight(player, enemy));
}

void FightHandler::Update()
{
	for (unsigned int i = 0; i < m_fights.size(); i++)
	{
		m_fights[i]->Update();
	}
}