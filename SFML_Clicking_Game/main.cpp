#include <SFML\Graphics.hpp>
#include "GameWindow.h"

int main(void) {
	GameWindow window(sf::VideoMode(1000, 1000), sf::String("name"), 30.0, sf::Vector2f(1000, 1000));
	sf::Event evnt;

	while (window.isOpen()) {
		window.eventCheck(evnt);
		window.setWindowDraw();
		window.display();
	}

	return 0;
}