#pragma once
#include "Places.h"
#include <SFML/Graphics.hpp>

class ClickingCircle : public sf::CircleShape {
private:
	sf::Vector2f winSize;
	sf::Vector2f centre;

public:
	ClickingCircle(float rad, sf::Vector2f windowSize);

	bool isClicked(sf::Vector2f cords);

	void changePosition();

	void draw(sf::RenderWindow* window);
};

