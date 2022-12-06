#pragma once
#ifndef GameObject_H
#define GameObject_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cassert>
#include <iostream>
#include "Throwings.h"
#include "Throwings_Gen.h"
using namespace sf;
using namespace std;

class GameObject {
private:
    Texture img;
    Sprite tamagotchi;
    int hit_time;
    Clock clock;
    bool hitted;
public:
    GameObject() {
        assert(img.loadFromFile("img/l_tamagotchi_img.png"));
        tamagotchi.setTexture(img);
        tamagotchi.setPosition(180.0f - 15.0f, 480.0f - 44.0f);

        hitted = false;
        hit_time = 0;
    }
    void moveLeft(void);
    void moveRight(void);
    void update(Throwings_Gen& _throwings, ScoreAndLife& _score);
    void draw(RenderWindow&);
    bool getHitted(void);
    void setHitted(bool);
    int getPos();

};

#endif