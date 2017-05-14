/*
@author Tobias F
@version 1.0 2017/05/14
*/

#ifndef MAINMENUSTATE_HPP
#define MAINMENUSTATE_HPP

#include "MenuState.h"
#include <string>

#define _NR_OF_OPTIONS_MAINMENU 3

namespace sf
{
	class Text;
	class Font;
}

class MainMenuState : public MenuState
{
public:
	MainMenuState(FiniteStateMachine* fsm);
	~MainMenuState();

	//bool Initialize() override;
	void Update() override;

private:
	void ProcessInput() override;
	void ClampSelecton();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	std::string m_options_string[_NR_OF_OPTIONS_MAINMENU] = {"Start","Settings","Quit" };
	enum m_options_enum {Start,Settings,Quit};

	sf::Text* m_text;
	sf::Font* m_font;
};

#endif