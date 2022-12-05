#pragma once
#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <SFML/Graphics.hpp>
#include <cassert>
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
    RenderWindow *window;
    RectangleShape rec;

public:
    GamePage() {

        window = new RenderWindow(VideoMode(360, 480), "TAMAGOTCHI - MINIGAME");
       
        RectangleShape rec(Vector2f(360, 480));
        cur_score = 0;
        cur_life = 5;


    }

    GamePage(int width, int height) {

        window = new RenderWindow(VideoMode(width, height), "TAMAGOTCHI - MINIGAME");
        //window.setFramerateLimit(60);

        //srand((unsigned int)time(NULL));
        //fontCheck(font, "Roboto - Regular.ttf");

        RectangleShape rec(Vector2f(360, 480));
        cur_score = 0;
        cur_life = 5;
        //rectangle(rec);

    }
    void gameStart(void);
    void rectangle(RectangleShape&);
    void gameStart(RenderWindow&, RectangleShape&, Font&);
    int fontCheck(Font&, string);
    void startPage(RenderWindow&, Font&);
    void endPage(RenderWindow&, Font&);
    int getScore(void);

};

#endif