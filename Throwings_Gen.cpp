#include "Throwings_Gen.h"
#include "Throwings.h"

void Throwings_Gen::update(ScoreAndLife& _score) {
    period = clock.getElapsedTime().asMilliseconds();

    //cout << "This is period : " <<period<<endl;

    if (period > rand() % 1000 + 300)
    {
        _x = (float)(rand() % 3300) / 10;   //좌우 범위에 대한
        _speed = (float)((rand() % 50) / 10) + 3; //50->35 정도는 어떨까?

        if (period % 5 == 1 || period % 5 == 3 || period % 5 == 5) {
            Throwings* ddong = new Throwings(_x, _speed, false);
            cout << "똥 푸쉬?" << endl;
            throwings.push_back(*ddong);
        }
        else if (period % 5 == 0 || period % 5 == 4) {
            //food ����� �κ�
            Throwings* food = new Throwings(_x, _speed, true);
            cout << "피자 푸쉬?" << endl;
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