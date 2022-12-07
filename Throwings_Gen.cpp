﻿#include "Throwings_Gen.h"
#include "Throwings.h"

void Throwings_Gen::update(ScoreAndLife& _score) {
    period = clock.getElapsedTime().asMilliseconds();
    clock_t end = std::clock();
    int t = (end - _score.getStart()) / 10000;

    if (period > rand() % 1000 + 300)
    {
        _x = (float)(rand() % 3300) / 10;
        _speed = (float)((rand() % 50) / 10) + 3 + t;

        if (period % 5 == 1 || period % 5 == 3 || period % 5 == 5) {
            Throwings* ddong = new Throwings(_x, _speed, false);
            throwings.push_back(*ddong);
        }
        else if (period % 5 == 0 || period % 5 == 4) {
            Throwings* food = new Throwings(_x, _speed, true);
            throwings.push_back(*food);
        }
        clock.restart();

    }

    for (auto& _e : throwings) {
        _e.update(_score);
    }
}

void Throwings_Gen::draw(RenderWindow& _window)
{
    for (auto& _e : throwings) {
        _e.draw(_window);
    }
};
bool Throwings_Gen::checkHit(FloatRect _rect, ScoreAndLife& _score) {
    for (auto& _e : throwings) {
        if (_rect.intersects(_e.getArea()) && !_e.destroyed) {
            if (_e.get_is_food()) {
                _score.upScore();
            }
            else {
                _score.downScore();
            }
            _e.destroyed = true;
            return true;
        }
    }
    return false;
};