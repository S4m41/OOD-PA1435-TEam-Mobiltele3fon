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
	m_enemies.push_back(new Enemy((rand() % 10) / 10 + 0.1f*(m_enemies.size() + 1)));
	m_enemies.back()->SetPosition(sf::Vector2f(float(rand() % 20), float(rand() % 20)) * 20.0f);
}

void EnemyHandler::Update()
{
	RemoveDeadEnemies();
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
void EnemyHandler::RemoveDeadEnemies() {
	if (!m_enemies.empty()) {
		for (int i = 0; i < GetNrOfEnemies(); i++) {
			if (m_enemies[i]->GetHealth() <= 0) {

			}
		}
	}
}
void EnemyHandler::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (unsigned int i = 0; i < m_enemies.size(); i++)
	{
		target.draw(*m_enemies[i], states);
	}
}