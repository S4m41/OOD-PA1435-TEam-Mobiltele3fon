#include "EnemyHandler.hpp"
#include "Enemy.hpp"
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>
#include <time.h>

EnemyHandler::EnemyHandler()
{
	srand((unsigned int)time(NULL));
}

EnemyHandler::~EnemyHandler()
{
	for (unsigned int i = 0; i < m_enemies.size(); i++)
	{
		delete m_enemies[i];
		m_enemies[i] = nullptr;
	}
}

void EnemyHandler::CreateEnemy()
{
	m_enemies.push_back(new Enemy);
	m_enemies.back()->SetPosition(sf::Vector2f(float(rand() % 20), float(rand() % 20)) * 20.0f);
}

void EnemyHandler::Update(sf::Vector2f playerPosition)
{
	for (unsigned int i = 0; i < m_enemies.size(); i++)
	{
		// Move towards player position
		m_enemies[i]->SetMovement(playerPosition - m_enemies[i]->GetPosition());
		m_enemies[i]->Update();
	}
}

void EnemyHandler::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (unsigned int i = 0; i < m_enemies.size(); i++)
	{
		target.draw(*m_enemies[i], states);
	}
}