/*
Abstrakt Klass

@author Tobias F
@version 1.0 2017/05/14
*/

#ifndef MENU_STATE_H
#define MENU_STATE_H
#include "GameState.hpp"
#include <String>

namespace sf
{
	class Text;
	class Font;
}
class MenuState : public GameState
{
public:
	MenuState(FiniteStateMachine* fsm);
	virtual ~MenuState();
	
	void Update() override;

	virtual void Notify(Event* keyDownEvent) override;

private:
	virtual void ClampSelecton() = 0;

protected:
	int m_selectedOption = 0;
	std::string m_title;
};

#endif // !MENUSTATE_H

