#include "InGame.h"

InGame::InGame(float rad, sf::Vector2f windowSize) : ScoreTexts(windowSize), ClickingCircle(rad, windowSize) {
	iGTexts = new sf::Text;

	iGTexts->setCharacterSize(50);

	iGTexts->setString(sf::String("PAUSE"));

	iGTexts->setPosition(sf::Vector2f(windowSize.x - 300, 0));
}

void InGame::draw(sf::RenderWindow* window) {
	ClickingCircle::draw(window);

	sTexts[0].setPosition(sf::Vector2f(0, 0));

	window->draw(*iGTexts);
	window->draw(sTexts[0]);
}

Places InGame::isClicked(sf::Vector2f cords) {
	if (ClickingCircle::isClicked(cords)) {
		curScore++;
		this->resetTexts();
		return NOTHING;
	}
	else if ((cords.x >= (ScoreTexts::winSize.x - 300) && cords.x <= (ScoreTexts::winSize.x)) && (cords.y >= (ScoreTexts::winSize.y) && cords.y <= (ScoreTexts::winSize.y + 50))) {
		return GAME_PAUSE;
	}
	else {
		return NOTHING;
	}
}

void InGame::changePosition() {
	ClickingCircle::changePosition();
}

InGame::~InGame() {
	delete iGTexts;
}