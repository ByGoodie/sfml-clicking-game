#include "ClickingCircle.h"

ClickingCircle::ClickingCircle(float rad, sf::Vector2f windowSize) : CircleShape(rad) {
	winSize = windowSize;

	this->setFillColor(sf::Color(255, 20, 147));

	centre.x = this->getPosition().x + rad;
	centre.y = this->getPosition().y + rad;
}

bool ClickingCircle::isClicked(sf::Vector2f cords) {
	cords.x = centre.x - cords.x;
	cords.y = centre.y - cords.y;

	if (sqrt((getSquare(cords.x) + getSquare(cords.y))) <= this->getRadius()) {

		changePosition();

		return true;
	}

	return false;
}

void ClickingCircle::changePosition() {
	sf::Vector2f posis = this->getPosition();
	sf::Vector2f nPosis(rand() % (int)(winSize.x - this->getRadius() * 2 + 1), rand() % (int)(winSize.y - this->getRadius() * 2 + 1));

	while (posis.x == nPosis.x && posis.y == nPosis.y) {
		nPosis.x = rand() % (int)(winSize.x - this->getRadius() * 2 + 1);
		nPosis.y = rand() % (int)(winSize.x - this->getRadius() * 2 + 1);
	}

	this->setPosition(nPosis);

	centre.x = this->getPosition().x + this->getRadius();
	centre.y = this->getPosition().y + this->getRadius();
}

void ClickingCircle::draw(sf::RenderWindow* window) {
	window->draw(*this);
}