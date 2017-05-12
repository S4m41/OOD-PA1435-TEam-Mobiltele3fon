#ifndef GAMEPLAYSTATE_HPP
#define GAMEPLAYSTATE_HPP
#include "GameState.hpp"
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>

class GamePlayState final : public GameState
{
public:
	GamePlayState(FiniteStateMachine* fsm);
	~GamePlayState();

	bool Initialize() override;
	void Update() override;

private:
	bool m_moveNorth, m_moveEast, m_moveSouth, m_moveWest;

	void ProcessInput() override;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif