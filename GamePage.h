#pragma once
#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <SFML/Graphics.hpp>
#include "Tamagotchi.h"
#include "Throwings.h"
#include "Throwings_Gen.h"
#include "ScoreAndLife.h"
using namespace sf;
using namespace std;

class GamePage {
private:
    Font font;
    Tamagotchi tamagotchi;
    Throwings_Gen throwings;
    ScoreAndLife score;
    Text textScore;
    Text textLife;
    int cur_score;
    int cur_life;
    RenderWindow window;
    RectangleShape rec;

public:
    GamePage() {

        RenderWindow window(VideoMode(360, 480), "TAMAGOTCHI - MINIGAME");
        //window.setFramerateLimit(60);

        //srand((unsigned int)time(NULL));
        //fontCheck(font, "Roboto - Regular.ttf");

        RectangleShape rec(Vector2f(360, 480));
        //rectangle(rec);



    }
    void rectangle(RectangleShape&);
    void gameStart(RenderWindow&);
    int fontCheck(Font&, string);
};

#endif