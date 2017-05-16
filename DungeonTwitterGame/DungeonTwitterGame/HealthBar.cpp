#include "HealthBar.hpp"
#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>

#define HEALTH_BAR_HEIGHT 5.0f
#define HEALTH_POINTS_PER_PIXEL 5

HealthBar::HealthBar(int characterWidth)
{
	m_maxHealth = new sf::RectangleShape(sf::Vector2f(float(characterWidth), HEALTH_BAR_HEIGHT));
	m_currentHealth = new sf::RectangleShape(sf::Vector2f(float(characterWidth), HEALTH_BAR_HEIGHT));

	m_maxHealth->setFillColor(sf::Color::Red);
	m_currentHealth->setFillColor(sf::Color::Green);
}

HealthBar::~HealthBar()
{
	if (m_maxHealth)
	{
		delete m_maxHealth;
		m_maxHealth = nullptr;
	}
	if (m_currentHealth)
	{
		delete m_currentHealth;
		m_currentHealth = nullptr;
	}
}

void HealthBar::SetPosition(sf::Vector2f characterPosition)
{
	float radius = m_maxHealth->getSize().x * 0.5f;
	sf::Vector2f position = characterPosition - sf::Vector2f(radius, radius + HEALTH_BAR_HEIGHT);
	m_maxHealth->setPosition(position);
	m_currentHealth->setPosition(position);
}

void HealthBar::ChangeHealth(int health)
{
	float newWidth = m_currentHealth->getSize().x + float(health) / HEALTH_POINTS_PER_PIXEL;
	newWidth = std::max(std::min(newWidth, m_maxHealth->getSize().x), 0.0f);				// Clamp

	m_currentHealth->setSize(sf::Vector2f(newWidth, HEALTH_BAR_HEIGHT));
}

int HealthBar::GetHealth() const
{
	return int(m_currentHealth->getSize().x * HEALTH_POINTS_PER_PIXEL);
}

void HealthBar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*m_maxHealth, states);
	target.draw(*m_currentHealth, states);
}