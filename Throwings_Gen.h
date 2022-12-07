#pragma once
#ifndef THROWINGS_GEN_H
#define THROWINGS_GEN_H

#include "Throwings.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Throwings_Gen {
private:
    vector <Throwings> throwings;
    float _x = 0;
    float _speed = 0;
    int period;
    Clock clock;
public:
    Throwings_Gen() {
        period = 0;
    }
    void update(ScoreAndLife&);
    void draw(RenderWindow&);
    bool checkHit(FloatRect, ScoreAndLife&);
};

#endif