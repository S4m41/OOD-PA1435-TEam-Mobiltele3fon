#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Entity.hpp"
//#include "Alternative.hpp"

class Character : public Entity
{
public:
	virtual ~Character();

	//bool Hit(int damage);
	//bool TryMoveCharacter(sf::Vector2f* direction);
	//Alternative* Interact();//TODO change return type
	//Alternative SelectAlternative(Alternative* alternative);
	//void Die();//TODO remove this? should be in characterhandler

	void SetWalkingSpeed(float speed);
	float GetWalkingSpeed() const;

	virtual void Update();

	void SetMovement(sf::Vector2f movement);

	sf::Vector2f GetMovement() const;

	void SetHealth(int health);
	int GetHealth() const;

protected:
	Character(sf::Color color);

private:
	sf::Vector2f m_movement;
	float m_walkingSpeed;
	int m_health;
};

#endif