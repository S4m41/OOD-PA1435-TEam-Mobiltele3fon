<<<<<<< HEAD
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

=======
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <SFML\Graphics\Drawable.hpp>
#include "Alternative.hpp"
class Character : public sf::Drawable
{
public:
	virtual ~Character();

	virtual void Update();

	bool Hit(int damage);
	bool TryMoveCharacter(sf::Vector2f* direction);
	Alternative* Interact();//TODO change return type
	Alternative SelectAlternative(Alternative* alternative);

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
	void Die();//TODO remove this? should be in characterhandler
	void MoveCharacter(sf::Vector2f direction);

private:
	sf::Vector2f m_position;
	float m_walkingSpeed;
	int m_health;

	bool m_moveUp, m_moveDown, m_moveRight, m_moveLeft;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

>>>>>>> Inventory
#endif