#include "CharacterHandler.hpp"
#include "PlayerHandler.hpp"
#include "EnemyHandler.hpp"
#include "FightHandler.hpp"
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>

CharacterHandler::CharacterHandler()
{
	m_playerHandler = new PlayerHandler;
	m_enemyHandler = new EnemyHandler;
	m_fightHandler = new FightHandler;

	m_playerHandler->CreatePlayer();

	for (int i = 0; i < 5; i++)
	{
		m_enemyHandler->CreateEnemy();
	}

	for (unsigned int i = 0; i < m_enemyHandler->GetNrOfEnemies(); i++)
	{
		m_fightHandler->StartFight(m_playerHandler->GetPlayer(), m_enemyHandler->GetEnemy(i));
	}
}

CharacterHandler::~CharacterHandler()
{
	if (m_playerHandler)
	{
		delete m_playerHandler;
		m_playerHandler = nullptr;
	}
	if (m_enemyHandler)
	{
		delete m_enemyHandler;
		m_enemyHandler = nullptr;
	}
	if (m_fightHandler)
	{
		delete m_fightHandler;
		m_fightHandler = nullptr;
	}	
}

void CharacterHandler::SetInput(Input* input)
{
	m_playerHandler->SetInput(input);
}

void CharacterHandler::Update()
{
	
	m_fightHandler->Update();
	m_playerHandler->Update();
	m_enemyHandler->Update();
}

void CharacterHandler::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*m_enemyHandler, states);
	target.draw(*m_playerHandler, states);
}

Player * CharacterHandler::GetPlayer()
{
	return m_playerHandler->GetPlayer();
}
