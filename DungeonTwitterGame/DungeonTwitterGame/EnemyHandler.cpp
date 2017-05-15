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

void EnemyHandler::Update()
{
	for (unsigned int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i]->Update();
	}
}

Enemy* EnemyHandler::GetEnemy(int i)
{
	return i >= 0 && i < m_enemies.size() ? m_enemies[i] : nullptr;
}
int EnemyHandler::GetNrOfEnemies() const
{
	return m_enemies.size();
}

void EnemyHandler::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (unsigned int i = 0; i < m_enemies.size(); i++)
	{
		target.draw(*m_enemies[i], states);
	}
}