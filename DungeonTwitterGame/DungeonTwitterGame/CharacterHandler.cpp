#include "CharacterHandler.hpp"
#include "PlayerHandler.hpp"
#include "EnemyHandler.hpp"
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>

CharacterHandler::CharacterHandler()
{
	m_playerHandler = new PlayerHandler;
	m_enemyHandler = new EnemyHandler;

	m_playerHandler->CreatePlayer();

	for (int i = 0; i < 5; i++)
	{
		m_enemyHandler->CreateEnemy();
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
}

void CharacterHandler::SetInput(Input* input)
{
	m_playerHandler->SetInput(input);
}

void CharacterHandler::Update()
{
	m_playerHandler->Update();
	m_enemyHandler->Update(m_playerHandler->GetPlayerPosition());
}

void CharacterHandler::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*m_enemyHandler, states);
	target.draw(*m_playerHandler, states);
}