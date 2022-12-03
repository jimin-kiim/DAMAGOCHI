#include "Throwings_Gen.h"
#include "Throwings.h"

void Throwings_Gen::update(Score& _score) {
	period = clock.getElapsedTime().asMilliseconds();
	//cout << "This is period : " <<period<<endl;
	if (period > rand() % 1000 + 300)
	{
		_x = (float)(rand() % 3300) / 10;
		_speed = (float)((rand() % 50) / 10) + 1;
		// 3으로 나누었을 때 나머지가 0 이면 ddong generate
		//ddong 만드는 부분
		if (period % 3 == 0) {
			Throwings* ddong = new Throwings(_x, _speed, false);
			ddongs.push_back(*ddong);
		}
		else {
			//food 만드는 부분
			Throwings* food = new Throwings(_x, _speed, true);
			foods.push_back(*food);
		}
		clock.restart();
	}

	//??
	for (auto& _e : foods) {
		_e.update(_score);
	}
}

void Throwings_Gen::draw(RenderWindow& _window)
{
	for (auto& _e : foods) {
		_e.draw(_window);
	}
};
bool Throwings_Gen::checkHit(FloatRect _rect) {
	for (auto& _e : foods) {
		if (_rect.intersects(_e.getArea()) == true && _e.destroyed == false) {
			_e.destroyed = true;
			return true;
		}
	}
	return false;
};