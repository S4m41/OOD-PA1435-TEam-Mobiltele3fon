#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\Color.hpp>

class Character : public sf::Drawable
{
public:
	virtual ~Character();

	virtual void Update();

	void SetPosition(sf::Vector2f position);
	sf::Vector2f GetPosition() const;

	void SetMovement(sf::Vector2f movement);
	sf::Vector2f GetMovement() const;

	void SetWalkingSpeed(float speed);
	float GetWalkingSpeed() const;

	void SetHealth(int health);
	int GetHealth() const;

protected:
	Character(sf::Color color);

private:
	sf::Vector2f m_position;
	sf::Vector2f m_movement;
	float m_walkingSpeed;
	int m_health;

	sf::Color m_color;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif