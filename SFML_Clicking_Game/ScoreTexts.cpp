#include "ScoreTexts.h"
#include <fstream>
#include <ios>
#include <cstdio>
#include <string>

ScoreTexts::ScoreTexts(sf::Vector2f windowSize) {
    sTexts = new sf::Text[2];

    winSize = windowSize;

    fnt.loadFromFile("arial.ttf");

    sTexts[0].setCharacterSize(50);
    sTexts[1].setCharacterSize(50);

    sTexts[0].setFont(fnt);
    sTexts[1].setFont(fnt);

    sTexts[0].setString(sf::String("Score: 0"));

    std::fstream file("bScore.txt", std::ios::in);

    char ch;

    int i = 0;

    char temp[100] = { 0 };

    if (file.is_open()) {
        while (!file.eof() && i < 93) {
            ch = (char)file.get();
            if (ch >= 48 && ch <= 57) {
                temp[i] = ch;
                i++;
            }
        }
    }
    else {
        temp[i] = '0';
        i++;
    }

    temp[i] = '\0';

    bestScore = atoi(temp);
    curScore = 0;

    sprintf_s(temp, 99, "Best: %d", bestScore);

    sTexts[1].setString(temp);
}

void ScoreTexts::resetTexts() {
    if (bestScore < curScore) {
        bestScore = curScore;
    }

    char temp[100];

    sprintf_s(temp, 99, "Score: %d", curScore);

    sTexts[0].setString(temp);

    sprintf_s(temp, 99, "Best: %d", bestScore);

    sTexts[1].setString(temp);
}

ScoreTexts::~ScoreTexts() {
    std::fstream file("bScore.txt", std::ios::out);

    if (file.is_open()) {
        file << bestScore;
    }

    delete[] sTexts;
}