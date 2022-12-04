#include "Throwings_Gen.h"
#include "Throwings.h"

void Throwings_Gen::update(Score& _score) {
	period = clock.getElapsedTime().asMilliseconds();
	//cout << "This is period : " <<period<<endl;
	if (0) {//is_fever) {
		for (int i = 0; i < 10; i++) {
			_x = (float)(330 * i);   //좌우 범위에 대한
			_speed = (float)((rand() % 50) / 10) + 1; //50->35 정도는 어떨까?
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
			// 3으로 나누었을 때 나머지가 0 이면 ddong generate
			//ddong 만드는 부분
			if (period % 3 == 0) {
				Throwings* ddong = new Throwings(_x, _speed, false);
				throwings.push_back(*ddong);
			}
			else {
				//food 만드는 부분
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
bool Throwings_Gen::checkHit(FloatRect _rect, Score & _score) {
	for (auto& _e : throwings) {
		if (_rect.intersects(_e.getArea()) == true && _e.destroyed == false) {
			if (_e.get_is_food() == true) {
				//다마고치가 먹는다.
				_score.upScore();
			}
			else{
				//다마고치가 힘들어한다.
				_score.downScore();
			}
			_e.destroyed = true;
			return true;
		}
	}
	return false;
};