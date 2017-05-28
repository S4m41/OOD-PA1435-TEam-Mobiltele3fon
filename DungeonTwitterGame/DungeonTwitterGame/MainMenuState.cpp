#include "MainMenuState.hpp"
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

MainMenuState::MainMenuState(FiniteStateMachine * fsm) : MenuState(fsm)
{
	m_font = new sf::Font;
	m_text = new sf::Text;

	m_title = "Main Menu";

	if (!m_font->loadFromFile("./Assets/Fonts/ALGER.TTF"))
	{
		std::cout << "Failed to load Font" << std::endl;
	}
	else
	{
		std::cout <<  "Font Loaded!" << std::endl;
	}
	m_text->setFont(*m_font);
}

MainMenuState::~MainMenuState()
{
	delete m_text;
	delete m_font;
}

void MainMenuState::Notify(Event* keyDownEvent)
{
	MenuState::Notify(keyDownEvent);

	KeyDownEvent* kde = dynamic_cast<KeyDownEvent*>(keyDownEvent);

	if (kde && kde->m_onlyPressed)
	{
		switch (kde->m_key)
		{
		case sf::Keyboard::Return:
			switch (m_selectedOption)
			{
			case Start:
				m_FSM->Push<PlayState>();		// Enter GamePlay state
				//m_FSM->Peek()->SetInput(m_input);
				break;
			case Quit:
				m_FSM->Pop();//Close Window
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}

void MainMenuState::Update()
{
	MenuState::Update();

	//if (m_input->IsKeyPressed(sf::Keyboard::Return)) {
	//	switch (m_selectedOption)
	//	{
	//	case Start:
	//		m_FSM->Push<PlayState>();		// Enter GamePlay state
	//		m_FSM->Peek()->SetInput(m_input);
	//		break;
	//	case Quit:
	//		m_FSM->Pop();//Close Window
	//		break;
	//	default:
	//		break;
	//	}
	//}
}

void MainMenuState::ClampSelecton()
{
	m_selectedOption += _NR_OF_OPTIONS_MAINMENU;
	m_selectedOption %= _NR_OF_OPTIONS_MAINMENU;
}

void MainMenuState::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	/*Draw Title*/
	m_text->setString(m_title);
	m_text->setCharacterSize(46); // in pixels, not points!							  
	m_text->setColor(sf::Color::Red);// set the color
	
	sf::FloatRect textRect = m_text->getLocalBounds();

	m_text->setPosition(WINDOW_WIDTH / 2 - textRect.width / 2, 10);
	m_text->setStyle(sf::Text::Bold);
	target.draw(*m_text, states);

	/*Draw Options*/
	for (int i = 0; i < _NR_OF_OPTIONS_MAINMENU; i++)
	{
		m_text->setString(m_options_string[i]);
		m_text->setCharacterSize(24); // in pixels, not points!							  
		m_text->setColor(sf::Color::Red);// set the color

		sf::FloatRect textRect = m_text->getLocalBounds();

		m_text->setPosition(WINDOW_WIDTH * 0.5f - textRect.width * 0.5f, WINDOW_HEIGHT * 0.5f - _NR_OF_OPTIONS_MAINMENU *25 + 50*i);
		// set the text style
		m_text->setStyle((m_selectedOption == i) ? sf::Text::Bold | sf::Text::Underlined : sf::Text::Bold);
		target.draw(*m_text, states);
	}
}
