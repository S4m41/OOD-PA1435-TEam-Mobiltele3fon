#ifndef GAMEPLAYSTATE_HPP
#define GAMEPLAYSTATE_HPP
#include "GameState.hpp"

class CharacterHandler;
namespace sf
{
	class RenderTarget;
	class RenderStates;
}

class GamePlayState final : public GameState
{
public:
	GamePlayState(FiniteStateMachine* fsm);
	~GamePlayState();

	void SetInput(Input* input) override;

	//bool Initialize() override;
	void Update() override;

private:
	CharacterHandler* m_characterHandler;

	void ProcessInput() override;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif