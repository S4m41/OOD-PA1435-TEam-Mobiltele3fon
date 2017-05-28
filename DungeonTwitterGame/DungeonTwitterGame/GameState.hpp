#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
#include <SFML\Graphics\Drawable.hpp>
#include "ObserverPattern.hpp"

//class Input;
class FiniteStateMachine;

class GameState : public sf::Drawable, public Observer
{
public:
	GameState(FiniteStateMachine* fsm);
	virtual ~GameState();

	//virtual void SetInput(Input* input);

	virtual void Notify(Event* keyDownEvent) override = 0;

	//virtual bool Initialize() = 0;
	virtual void Update() = 0;

protected:
	//Input* m_input;
	FiniteStateMachine* m_FSM;
};

#endif