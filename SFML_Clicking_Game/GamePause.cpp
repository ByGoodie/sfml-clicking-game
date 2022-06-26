#include "GamePause.h"

GamePause::GamePause(sf::Vector2f windowSize) : ScoreTexts(windowSize) {
    gPTexts = new sf::Text[2];

    gPTexts[0].setCharacterSize(50);
    gPTexts[1].setCharacterSize(50);

    gPTexts[0].setFont(fnt);
    gPTexts[1].setFont(fnt);

    gPTexts[0].setString(sf::String("CONTINUE"));
    gPTexts[1].setString(sf::String("BACK TO MENU"));

    gPTexts[0].setPosition(sf::Vector2f(windowSize.x / 2 - 225, windowSize.y / 2 - 50));
    gPTexts[1].setPosition(sf::Vector2f(windowSize.x / 2 - 325, windowSize.y / 2));
}

void GamePause::draw(sf::RenderWindow* window) {
    window->clear(sf::Color::Black);

    sTexts[0].setPosition(sf::Vector2f(0, winSize.y - 50));
    sTexts[1].setPosition(sf::Vector2f(winSize.x - 500, winSize.y - 50));

    window->draw(gPTexts[0]);
    window->draw(gPTexts[1]);
    window->draw(sTexts[0]);
    window->draw(sTexts[1]);
}

Places GamePause::isClicked(sf::Vector2f cords) {
    if ((cords.x >= (winSize.x / 2 - 225) && cords.x <= (winSize.x / 2 + 225)) && (cords.y >= (winSize.y / 2 - 50) && cords.y <= (winSize.y / 2))) {
        return IN_GAME;
    }
    else if ((cords.x >= (winSize.x / 2 - 325) && cords.x <= (winSize.x / 2 + 325)) && (cords.y >= (winSize.y / 2) && cords.y <= (winSize.y / 2 + 50))) {
        curScore = 0;
        return MENU;
    }
    else {
        return NOTHING;
    }
}

GamePause:: ~GamePause() {
    delete[] gPTexts;
}