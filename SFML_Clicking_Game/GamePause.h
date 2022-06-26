#pragma once
#include "ScoreTexts.h"
#include "Places.h"

class GamePause : virtual protected ScoreTexts {
private:
    sf::Text* gPTexts;

public:
    GamePause(sf::Vector2f windowSize);

    void draw(sf::RenderWindow* window);

    Places isClicked(sf::Vector2f cords);

    ~GamePause();
};

