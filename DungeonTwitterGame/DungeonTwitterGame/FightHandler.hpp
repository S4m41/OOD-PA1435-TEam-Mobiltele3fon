#ifndef FIGHT_HANDLER_HPP
#define FIGHT_HANDLER_HPP
#include <vector>

class Player;
class Enemy;
class Fight;

class FightHandler final
{
public:
	FightHandler();
	~FightHandler();

	void StartFight(Player* player, Enemy* enemy);

	void Update();
	
private:
	std::vector<Fight*> m_fights;
};

#endif