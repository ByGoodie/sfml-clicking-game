#pragma once
#include "Places.h"
#include <SFML/Graphics.hpp>
#include "InGame.h"
#include "GamePause.h"
#include "Menu.h"
#include "timer.h"

class GameWindow : public sf::RenderWindow, private Menu, private GamePause, private InGame {
private:
	Places curPlace;
	timer startTime{ 30 };
	sf::Vector2f curMCords;

public:
	GameWindow(sf::VideoMode vMode, sf::String name, float rad, sf::Vector2f windowSize);

	void eventCheck(sf::Event& evnt);

	void setWindowDraw();

	void keyBoardCheck(sf::Event& evnt);

	void mouseCheck(sf::Event& evnt);
};

