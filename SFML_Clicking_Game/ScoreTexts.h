#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <ios>

class ScoreTexts {
protected:
    sf::Text* sTexts;
    sf::Font fnt;
    sf::Vector2f winSize;
    int curScore, bestScore;

public:
    ScoreTexts(sf::Vector2f windowSize);

    void resetTexts();

    ~ScoreTexts();
};

