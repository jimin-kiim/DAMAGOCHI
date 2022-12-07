#include "Throwings.h"
#include "ScoreAndLife.h"

void Throwings::update(ScoreAndLife& score) {
    if (destroyed == true) {
        return;
    }
    if (this->is_food) {
        Vector2f pos = food.getPosition();
        if (pos.y > 480.0f - 26.0f) {
            speed = 0;
            destroyed = true;

            clock.restart();
        }
        food.move(0.0f, 1.0f * speed);

    }
    else {
        Vector2f pos = ddong.getPosition();
        if (pos.y > 480.0f - 26.0f) {
            speed = 0;
            destroyed = true;

            clock.restart();
        }
        ddong.move(0.0f, 1.0f * speed);
    }
};
void Throwings::draw(RenderWindow& _window) {
    if (destroyed) {
        if (clock.getElapsedTime().asMilliseconds() > 500) {
            return;
        }
    }
    if (is_food) {
        _window.draw(food);

    }
    else {
        _window.draw(ddong);
    }
};
FloatRect Throwings::getArea() {
    if (this->is_food) {
        return food.getGlobalBounds();
    }
    else {
        return ddong.getGlobalBounds();
    }
};
bool Throwings::get_is_food(void) {
    return (this->is_food);
};