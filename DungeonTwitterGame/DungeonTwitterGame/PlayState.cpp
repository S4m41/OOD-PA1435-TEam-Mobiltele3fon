#include "PlayState.hpp"
#include "PauseMenuState.hpp"
#include "RoomHandler.hpp"
#include "Input.hpp"
#include "FiniteStateMachine.hpp"
#include "Player.hpp"

#include <SFML\Window\Keyboard.hpp>
#include <SFML\Graphics\CircleShape.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>

#include <iostream>

PlayState::PlayState(FiniteStateMachine* fsm) : GameState(fsm)
{
	m_RoomHandler = new RoomHandler(/*L"seedName"*/);
}

PlayState::~PlayState()
{
	if (m_RoomHandler)
	{
		delete m_RoomHandler;
		m_RoomHandler = nullptr;
	}
}

void PlayState::Notify(Event* keyDownEvent)
{
	KeyDownEvent* kde = dynamic_cast<KeyDownEvent*>(keyDownEvent);
	if (kde)
	{
		if (kde->m_onlyPressed)
		{
			switch (kde->m_key)
			{
			case sf::Keyboard::Key::Escape:
				m_FSM->Push<PauseMenuState>();		// Enter pause state
				break;
			case sf::Keyboard::Key::E:
			{
				std::cout << "E pressed" << std::endl;

				sf::Vector2f currentPosition = m_RoomHandler->GetPlayer()->GetPosition();
				bool roomEntered = false;

				for (unsigned int i = 0; i < 4 && !roomEntered; i++)
				{
					//std::cout << "Failed To Enter" << std::endl;
					sf::Vector2f distance = currentPosition - DoorPositionArray[i];
					if (abs(distance.x) < 50.0f && abs(distance.y) < 50.0f)
					{
						if (m_RoomHandler->EnterRoom(i))
						{
							m_RoomHandler->GetPlayer()->SetPosition(DoorPositionArray[(i + 2) % 4]);
							roomEntered = true;
						}
					}
				}
				if (!roomEntered)
					m_RoomHandler->CheckItemPickUp(m_RoomHandler->GetPlayer());
				break;
			}
			case sf::Keyboard::Key::Num1:
				std::cout << "Inventory Slot 1 Selected\n";
				m_RoomHandler->GetPlayer()->SetActiveItem(0);
				break;
			case sf::Keyboard::Key::Num2:
				std::cout << "Inventory Slot 2 Selected\n";
				m_RoomHandler->GetPlayer()->SetActiveItem(1);
				break;
			case sf::Keyboard::Key::Num3:
				std::cout << "Inventory Slot 3 Selected\n";
				m_RoomHandler->GetPlayer()->SetActiveItem(2);
				break;
			default:
				break;
			}
		}
	}
}

//void PlayState::SetInput(Input* input)
//{
//	GameState::SetInput(input);
//	m_RoomHandler->SetInput(input);
//}

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
	//if (m_input->IsKeyPressed(sf::Keyboard::Escape))
	//{
	//	m_FSM->Push<PauseMenuState>();		// Enter pause state
	//	m_FSM->Peek()->SetInput(m_input);
	//}
	//if (m_input->IsKeyPressed(sf::Keyboard::Key::E))
	//{
	//	std::cout << "E pressed" << std::endl;


	//	sf::Vector2f currentPosition = m_RoomHandler->GetPlayer()->GetPosition();
	//	bool roomEntered = false;

	//	for (unsigned int i = 0; i < 4 && !roomEntered; i++)
	//	{
	//		//std::cout << "Failed To Enter" << std::endl;
	//		sf::Vector2f distance = currentPosition - DoorPositionArray[i];
	//		if (abs(distance.x) < 50.0f && abs(distance.y) < 50.0f)
	//		{
	//			if (m_RoomHandler->EnterRoom(i))
	//			{
	//				m_RoomHandler->GetPlayer()->SetPosition(DoorPositionArray[(i + 2) % 4]);
	//				roomEntered = true;
	//			}
	//		}
	//	}

	//	if (!roomEntered) {
	//		m_RoomHandler->CheckItemPickUp(m_RoomHandler->GetPlayer());
	//	}
	//}

	//if(m_input->IsKeyPressed(sf::Keyboard::Num1)) {
	//	std::cout << "Inventory Slot 1 Selected" << std::endl;
	//	m_RoomHandler->GetPlayer()->SetActiveItem(0);
	//}
	//else if (m_input->IsKeyPressed(sf::Keyboard::Num2)) {
	//	std::cout << "Inventory Slot 2 Selected" << std::endl;
	//	m_RoomHandler->GetPlayer()->SetActiveItem(1);
	//}
	//else if (m_input->IsKeyPressed(sf::Keyboard::Num3)) {
	//	std::cout << "Inventory Slot 3 Selected" << std::endl;
	//	m_RoomHandler->GetPlayer()->SetActiveItem(2);
	//}

	m_RoomHandler->Update();
}

void PlayState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*m_RoomHandler, states);
}