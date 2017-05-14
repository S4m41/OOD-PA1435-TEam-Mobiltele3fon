#ifndef MAINMENUSTATE_HPP
#define MAINMENUSTATE_HPP

#include "GameState.hpp"
#include <string>

#define _NR_OF_OPTIONS 3

namespace sf
{
	class Text;
	class Font;
}

class MainMenuState : public GameState
{
public:
	MainMenuState(FiniteStateMachine* fsm);
	~MainMenuState();

	void SetInput(Input* input) override;

	//bool Initialize() override;
	void Update() override;

private:
	void ProcessInput() override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	std::string m_options_string[_NR_OF_OPTIONS] = {"Start","Settings","Quit" };
	enum m_options_enum {Start,Settings,Quit};

	int m_selectedOption = 0;
	sf::Text* m_text;
	sf::Font* m_font;
};

#endif