#ifndef PAUSE_MENU_STATE_HPP
#define PAUSE_MENU_STATE_HPP
#include "GameState.hpp"

namespace sf
{
	class RenderTarget;
	class RenderStates;
}

class PauseMenuState final : public GameState
{
public:
	PauseMenuState(FiniteStateMachine* fsm);
	~PauseMenuState();

	//bool Initialize() override;
	void Update() override;

private:
	// .
	// .
	// .
	// Data
	// .
	// .

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif