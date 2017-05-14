/*
Abstrakt Klass

@author Tobias F
@version 1.0 2017/05/14
*/

#ifndef MENU_STATE_H
#define MENU_STATE_H
#include "GameState.hpp"

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

private:
	virtual void ClampSelecton() = 0;

protected:
	void ProcessInput();
	int m_selectedOption = 0;
};

#endif // !MENUSTATE_H
