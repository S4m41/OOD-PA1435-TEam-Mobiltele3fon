#ifndef GAME_PAUSE_MENU_STATE_HPP
#define GAME_PAUSE_MENU_STATE_HPP
#include "GameState.hpp"

namespace sf
{
	class RenderTarget;
	class RenderStates;
}

class GamePauseMenuState final : public GameState
{
public:
	GamePauseMenuState(FiniteStateMachine* fsm);
	~GamePauseMenuState();

	//bool Initialize() override;
	void Update() override;

private:
	// .
	// .
	// .
	// Data
	// .
	// .

	void ProcessInput() override;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif