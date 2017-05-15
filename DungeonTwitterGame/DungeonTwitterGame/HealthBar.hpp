#ifndef HEALTH_BAR_HPP
#define HEALTH_BAR_HPP
#include <SFML\Graphics\Drawable.hpp>

namespace sf
{
	class RectangleShape;
}

class HealthBar final : public sf::Drawable
{
public:
	HealthBar(int characterWidth);
	~HealthBar();

	void SetPosition(sf::Vector2f characterPosition);

	void ChangeHealth(int health);
	int GetHealth() const;

private:
	sf::RectangleShape* m_maxHealth;
	sf::RectangleShape* m_currentHealth;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif