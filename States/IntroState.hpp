#pragma once

#include <functional>

#include "State.hpp"
#include "Application.hpp"

class IntroState : public State
{
public:
	IntroState(StateStack& stack, Context context);

	virtual void initGui();

	virtual bool update(sf::Time dt);
	virtual bool handleEvent(const sf::Event& event);
	virtual void draw();

private:
	sfg::Window::Ptr mainWindow, loadWindow;

	sfg::Box::Ptr mainBox, loadBox;

	sfg::Button::Ptr playButton, settingsButton, creditsButton, exitButton, newGameButton, loadGameButton;
	sfg::Label::Ptr title;

	void playButtonClicked();
	void settingsButtonClicked();
};