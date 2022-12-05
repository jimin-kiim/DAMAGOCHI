#include "Throwings_Gen.h"
#include "Throwings.h"

void Throwings_Gen::update(ScoreAndLife& _score) {
    period = clock.getElapsedTime().asMilliseconds();
    //cout << "This is period : " <<period<<endl;
    if (0) {//is_fever) {
        for (int i = 0; i < 10; i++) {
            _x = (float)(330 * i);   //¡¬øÏ π¸¿ßø° ¥Î«—
            _speed = (float)((rand() % 50) / 10) + 1; //50->35 ¡§µµ¥¬ æÓ∂≥±Ó?
            Throwings* food = new Throwings(_x, _speed, true);
            throwings.push_back(*food);
            sleep(sf::microseconds(1));
        }
        clock.restart();
    }
    else {
        if (period > rand() % 1000 + 300)
        {
            _x = (float)(rand() % 3300) / 10;
            _speed = (float)((rand() % 50) / 10) + 1;
            // 3¿∏∑Œ ≥™¥©æ˙¿ª ∂ß ≥™∏”¡ˆ∞° 0 ¿Ã∏È ddong generate
            //ddong ∏∏µÂ¥¬ ∫Œ∫–
            if (period % 5 == 0) {
                Throwings* ddong = new Throwings(_x, _speed, false);
                throwings.push_back(*ddong);
            }
            else if (period % 5 == 1 || period % 5 == 3) {
                //food ∏∏µÂ¥¬ ∫Œ∫–
                Throwings* food = new Throwings(_x, _speed, true);
                throwings.push_back(*food);
            }
            clock.restart();
        }
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
        if (_rect.intersects(_e.getArea()) == true && _e.destroyed == false) {
            if (_e.get_is_food() == true) {
                //¥Ÿ∏∂∞Ìƒ°∞° ∏‘¥¬¥Ÿ.
                _score.upScore();
            }
            else {
                //¥Ÿ∏∂∞Ìƒ°∞° »˚µÈæÓ«—¥Ÿ.
                _score.downScore();
            }
            _e.destroyed = true;
            return true;
        }
    }
    return false;
};