#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "Character.hpp"

class Enemy final : public Character
{
public:
	Enemy(float speed);
	~Enemy();

	void Update();

private:
	// AI

};

#endif