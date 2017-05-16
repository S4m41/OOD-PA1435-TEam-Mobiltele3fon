#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Character.hpp"

class Player final : public Character
{
public:
	Player(bool isRanged=true);
	~Player();

	void Update();

	void SetMoveUp();
	void SetMoveDown();
	void SetMoveRight();
	void SetMoveLeft();

private:
	bool m_moveUp, m_moveDown, m_moveRight, m_moveLeft;
};

#endif