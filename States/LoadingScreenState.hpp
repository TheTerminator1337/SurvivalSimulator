#pragma once

#include "State.hpp"
#include "Application.hpp"
#include "GameState.hpp"

class LoadingScreenState : public State
{
public:
	LoadingScreenState(StateStack& stack, Context context);

	virtual void initGui();

	virtual bool update(sf::Time dt);
	virtual bool handleEvent(const sf::Event& event);
	virtual void draw();

private:
	float m_elapsedTime;

	sf::Font m_loadingFont;
	sf::Text m_loadingText;
};