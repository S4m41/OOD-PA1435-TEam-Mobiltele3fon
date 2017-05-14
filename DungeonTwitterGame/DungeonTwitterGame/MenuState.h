/*
Abstrakt Klass

@author Tobias F
@version 1.0 2017/05/14
*/

#ifndef MENUSTATE_H
#define MENUSTATE_H
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

private:
	virtual void ClampSelecton() = 0;

protected:
	void ProcessInput();
	int m_selectedOption = 0;
	std::string m_title;
};

#endif // !MENUSTATE_H

