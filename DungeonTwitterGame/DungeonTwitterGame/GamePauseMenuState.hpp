#ifndef GAME_PAUSE_MENU_STATE_HPP
#define GAME_PAUSE_MENU_STATE_HPP
#include "MenuState.h"
/*
@author Tobias F
@version 1.0 2017/05/14
*/

#include <String>
#define _NR_OF_OPTIONS_PAUSEMENU 2

namespace sf
{
	class RenderTarget;
	class RenderStates;
	class Text;
	class Font;
}

class GamePauseMenuState final : public MenuState
{
public:
	GamePauseMenuState(FiniteStateMachine* fsm);
	~GamePauseMenuState();

	//bool Initialize() override;
	void Update() override;

private:
	void ClampSelecton();
	void ProcessInput() override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	std::string m_options_string[_NR_OF_OPTIONS_PAUSEMENU] = { "Resume","Quit" };
	enum m_options_enum { Resume, Quit };

	sf::Text* m_text;
	sf::Font* m_font;
};

#endif