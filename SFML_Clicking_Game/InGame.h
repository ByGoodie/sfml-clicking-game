#pragma once
#include "ScoreTexts.h"
#include "ClickingCircle.h"
#include "Places.h"

class InGame : virtual protected ScoreTexts, private ClickingCircle {
private:
	sf::Text* iGTexts;

public:
	InGame(float rad, sf::Vector2f windowSize);

	void draw(sf::RenderWindow* window);

	void changePosition();

	Places isClicked(sf::Vector2f cords);

	~InGame();
};
