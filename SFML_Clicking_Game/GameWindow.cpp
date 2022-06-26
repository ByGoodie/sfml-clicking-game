#include "GameWindow.h"

GameWindow::GameWindow(sf::VideoMode vMode, sf::String name, float rad, sf::Vector2f windowSize) : RenderWindow(vMode, name), Menu(windowSize), GamePause(windowSize), InGame(rad, windowSize), ScoreTexts(windowSize) {
	startTime.tStop();
	curMCords.x = 0;
	curMCords.y = 0;
	curPlace = MENU;
}

void GameWindow::eventCheck(sf::Event& evnt) {
	if (this->pollEvent(evnt)) {
		if (evnt.type == sf::Event::Closed) {
			this->close();
		}
		else {
			keyBoardCheck(evnt);
			mouseCheck(evnt);
		}
	}

	if (curPlace == IN_GAME) {
		startTime.calcTime();

		if (startTime.isFinish()) {
			curScore = 0;
			startTime.reset();
			startTime.tStop();
			curPlace = MENU;
		}
	}
}

void GameWindow::setWindowDraw() {
	if (curPlace == MENU) {
		this->clear(sf::Color::Black);
		this->Menu::draw(this);
	}
	else if (curPlace == GAME_PAUSE) {
		this->clear(sf::Color::Black);
		this->GamePause::draw(this);
	}
	else if (curPlace == IN_GAME) {
		this->clear(sf::Color::Black);
		this->InGame::draw(this);
	}
}

void GameWindow::keyBoardCheck(sf::Event& evnt) {
	if (evnt.type == sf::Event::KeyPressed) {
		if (evnt.key.code == sf::Keyboard::Escape) {
			if (curPlace == GAME_PAUSE) {
				curPlace = IN_GAME;
				startTime.tContinue();
			}
			else if (curPlace == IN_GAME) {
				startTime.tStop();
				curPlace = GAME_PAUSE;
			}
		}
	}
}

void GameWindow::mouseCheck(sf::Event& evnt) {
	if (evnt.type == sf::Event::MouseButtonPressed) {
		if (curPlace == MENU) {
			Places place;
			if ((place = Menu::isClicked(curMCords)) != NOTHING) {
				curPlace = place;
				this->changePosition();
				startTime.tContinue();
			}
		}
		else if (curPlace == GAME_PAUSE) {
			Places place;
			if ((place = GamePause::isClicked(curMCords)) != NOTHING) {
				if (place == MENU) {
					curScore = 0;
					startTime.reset();
					startTime.tStop();
					this->resetTexts();
					curPlace = place;
				}
				else if (place == IN_GAME) {
					startTime.tContinue();
					curPlace = place;
				}
			}
		}
		else if (curPlace == IN_GAME) {
			Places place;
			if ((place = InGame::isClicked(curMCords)) != NOTHING) {
				startTime.tStop();
				curPlace = place;
			}
		}
	}
	else if (evnt.type == sf::Event::MouseMoved) {
		curMCords.x = evnt.mouseMove.x;
		curMCords.y = evnt.mouseMove.y;
	}
}