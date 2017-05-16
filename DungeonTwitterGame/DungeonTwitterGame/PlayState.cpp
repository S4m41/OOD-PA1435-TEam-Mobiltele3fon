#include "PlayState.hpp"
#include "PauseMenuState.hpp"
#include "CharacterHandler.hpp"
#include "RoomHandler.hpp"
#include "Input.hpp"
#include "FiniteStateMachine.hpp"
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Graphics\CircleShape.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>

PlayState::PlayState(FiniteStateMachine* fsm) : GameState(fsm)
{
	m_characterHandler = new CharacterHandler;
	m_RoomHandler = new RoomHandler(L"seedName");
}

PlayState::~PlayState()
{
	if (m_characterHandler)
	{
		delete m_characterHandler;
		m_characterHandler = nullptr;
	}
}

void PlayState::SetInput(Input* input)
{
	GameState::SetInput(input);
	m_characterHandler->SetInput(input);
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
	if (m_input->IsKeyPressed(sf::Keyboard::Escape))
	{
		m_FSM->Push<PauseMenuState>();		// Enter pause state
		m_FSM->Peek()->SetInput(m_input);
	}

	m_characterHandler->Update();
}

void PlayState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*m_characterHandler, states);
}