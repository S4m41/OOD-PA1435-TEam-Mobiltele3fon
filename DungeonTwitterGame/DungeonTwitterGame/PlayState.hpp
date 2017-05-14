#ifndef PLAY_STATE_HPP
#define PLAY_STATE_HPP

#include "GameState.hpp"
#include "RoomHandler.hpp"

class CharacterHandler;
namespace sf
{
	class RenderTarget;
	class RenderStates;
}

class PlayState final : public GameState
{
public:
	PlayState(FiniteStateMachine* fsm);
	~PlayState();

	void SetInput(Input* input) override;

	//bool Initialize() override;
	void Update() override;

private:
	CharacterHandler* m_characterHandler;
	RoomHandler* m_RoomHandler;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif