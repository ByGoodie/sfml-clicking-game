#pragma once
#include "ScoreTexts.h"
#include "Places.h"

class Menu : virtual protected ScoreTexts{
private:
    sf::Text* mTexts;

public:
    Menu(sf::Vector2f windowSize);

    void draw(sf::RenderWindow* window);

    Places isClicked(sf::Vector2f cords);

    ~Menu();
};

