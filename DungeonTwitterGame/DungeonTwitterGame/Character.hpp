#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <SFML\Graphics\Drawable.hpp>

class Character : public sf::Drawable
{
public:
	virtual ~Character();

	virtual void Update();

	void SetPosition(sf::Vector2f position);
	sf::Vector2f GetPosition() const;

	void SetMoveUp();
	void SetMoveDown();
	void SetMoveRight();
	void SetMoveLeft();

	void SetHealth(int health);
	int GetHealth() const;

protected:
	Character();

private:
	sf::Vector2f m_position;
	float m_walkingSpeed;
	int m_health;

	bool m_moveUp, m_moveDown, m_moveRight, m_moveLeft;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif