#include "Menu.h"

Menu::Menu(sf::Vector2f windowSize) : ScoreTexts(windowSize) {
    mTexts = new sf::Text;

    mTexts->setString("PLAY");
    mTexts->setCharacterSize(100);

    mTexts->setPosition(windowSize.x / 2 - 200, windowSize.y / 2 - 50);
    sTexts[1].setPosition(windowSize.x / 2 - 200, windowSize.y / 2 + 50);

    mTexts->setFont(fnt);
}

void Menu::draw(sf::RenderWindow* window) {
    window->clear(sf::Color::Black);
    window->draw(*mTexts);

    sTexts[1].setPosition(winSize.x / 2 - 200, winSize.y / 2 + 50);

    window->draw(sTexts[1]);
}

Places Menu::isClicked(sf::Vector2f cords) {
    if ((cords.x >= (winSize.x / 2 - 200) && cords.x <= (winSize.y / 2 + 200) && (cords.y >= (winSize.y / 2 - 50) && cords.y <= (winSize.y / 2 + 50)))) {
        return IN_GAME;
    }

    return NOTHING;
}

Menu::~Menu() {
    delete mTexts;
}