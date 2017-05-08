#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
#include "State.hpp"

class GameState final : public State
{
public:
	GameState();
	~GameState();

	bool Initialize();

	void ProcessKeyDown(int i);
	void ProcessKeyPressed(int i);

	void Update();
};

#endif