#ifndef FIGHT_HPP
#define FIGHT_HPP

class Player;
class Enemy;

class Fight final
{
public:
	Fight(Player* player, Enemy* enemy);
	~Fight();

	void Update();

private:
	Player* m_player;
	Enemy* m_enemy;
};

#endif