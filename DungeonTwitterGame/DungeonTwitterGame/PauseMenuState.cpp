#include "PauseMenuState.hpp"

#include "Input.hpp"
#include "SystemSettings.hpp"
#include "FiniteStateMachine.hpp"
#include "PlayState.hpp"

#include <SFML\Window\Keyboard.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\Graphics\Font.hpp>
#include <SFML\Graphics\Text.hpp>

#include<iostream>

PauseMenuState::PauseMenuState(FiniteStateMachine* fsm) : MenuState(fsm)
{
	m_font = new sf::Font;
	m_text = new sf::Text;

	if (!m_font->loadFromFile("./Graphics/Fonts/ALGER.TTF"))
	{
		std::cout << "Failed to load Font" << std::endl;
	}
	else
	{
		std::cout << "Font Loaded!" << std::endl;
	}
	m_text->setFont(*m_font);
}

PauseMenuState::~PauseMenuState()
{
	delete m_text;
	delete m_font;
}

void PauseMenuState::Update()
{
	ProcessInput();
}

void PauseMenuState::ProcessInput()
{
	if (m_input->IsKeyPressed(sf::Keyboard::Key::Escape))
	{
		m_FSM->Pop();		// Exit pause state, return to play state
		return;
	}

	MenuState::ProcessInput();//Up and Down key checked in baseClass!

	if (m_input->IsKeyPressed(sf::Keyboard::Return)) {
		switch (m_selectedOption)
		{
		case Resume:
			m_FSM->Pop();		// Exit pause state, return to play state
			return;
			break;
		case Quit:
			m_FSM->Pop(2);		// Exit pause state, return to MainMenu state
			return;
			return;
		default:
			break;
		}
	}
}

void PauseMenuState::ClampSelecton()
{
	m_selectedOption += _NR_OF_OPTIONS_PAUSEMENU;
	m_selectedOption %= _NR_OF_OPTIONS_PAUSEMENU;
}

void PauseMenuState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < _NR_OF_OPTIONS_PAUSEMENU; i++)
	{
		m_text->setString(m_options_string[i]);
		m_text->setCharacterSize(24); // in pixels, not points!

		m_text->setColor(sf::Color::Red);// set the color

		sf::FloatRect textRect = m_text->getLocalBounds();

		m_text->setPosition(WINDOW_WIDTH * 0.5f - textRect.width * 0.5f, WINDOW_HEIGHT * 0.5f - _NR_OF_OPTIONS_PAUSEMENU * 25 + 50 * i);
		// set the text style
		m_text->setStyle((m_selectedOption == i) ? sf::Text::Bold | sf::Text::Underlined : sf::Text::Bold);
		target.draw(*m_text, states);
	}
}