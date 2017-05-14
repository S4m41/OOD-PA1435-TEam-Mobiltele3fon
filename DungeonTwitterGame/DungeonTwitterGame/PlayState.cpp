#include "PlayState.hpp"
#include "PauseMenuState.hpp"
#include "CharacterHandler.hpp"
#include "Input.hpp"
#include "FiniteStateMachine.hpp"
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Graphics\CircleShape.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>

PlayState::PlayState(FiniteStateMachine* fsm) : GameState(fsm)
{
	//m_characterHandler = new CharacterHandler;
	//m_characterHandler->AddPlayer();
}
PlayState::~PlayState()
{
	/*if (m_characterHandler)
	{
		delete m_characterHandler;
		m_characterHandler = nullptr;
	}*/
}

void PlayState::SetInput(Input* input)
{
	GameState::SetInput(input);
	//m_characterHandler->SetInput(input);
}

//bool GamePlayState::Initialize()
//{
//	// Create entities and such
//	// ...
//	// ...
//	// ...
//	// ...
//	return true;
//}

void PlayState::Update()
{
	ProcessInput();

	//m_characterHandler->Update();
}
void PlayState::ProcessInput()
{
	/*m_moveNorth = m_input->IsKeyDown(sf::Keyboard::W);
	m_moveEast = m_input->IsKeyDown(sf::Keyboard::D);
	m_moveSouth = m_input->IsKeyDown(sf::Keyboard::S);
	m_moveWest = m_input->IsKeyDown(sf::Keyboard::A);*/

	if (m_input->IsKeyPressed(sf::Keyboard::Escape))
	{
		m_FSM->Push<PauseMenuState>();		// Enter pause state
		m_FSM->Peek()->SetInput(m_input);
	}
}

void PlayState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape circle(100.0f);
	circle.setFillColor(sf::Color::Blue);
	target.draw(circle, states);

	//target.draw(*m_characterHandler, states);
}