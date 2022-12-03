#include "Throwings.h"
#include "Score.h"

void Throwings::update(Score& score) {
	if (destroyed == true) {
		return;
	}
	if (this->is_food == true) {
		Vector2f pos = food.getPosition();
		//¶¥¿¡ ´ê¾ÒÀ» ¶§
		if (pos.y > 480.0f - 26.0f) {
			speed = 0;
			destroyed = true;

			clock.restart();
		}
		food.move(0.0f, 1.0f * speed);

	}
	else if (this->is_food == false) {
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
	if (destroyed == true) {
		if (clock.getElapsedTime().asMilliseconds() > 500) {
			return;
		}
	}
	if (is_food == true) {
		_window.draw(food);

	}
	else {
		_window.draw(ddong);
	}
};
FloatRect Throwings::getArea() {
	if (this->is_food == true) {
		return food.getGlobalBounds();
	}
	else {
		return ddong.getGlobalBounds();
	}
};