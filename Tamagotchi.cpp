#include "Tamagotchi.h"
#include "Throwings.h"
#include "Throwings_Gen.h"
#include "Score.h"

void Tamagotchi::moveLeft(void) {
	if (tamagotchi.getPosition().x <= 0.0f) {
		return;
	}
	tamagotchi.move(-10.0f, 0.0f);
}

void Tamagotchi::moveRight(void) {
	if (tamagotchi.getPosition().x >= 360.0f - 30.0f){
		return;
	}
	tamagotchi.move(10.0f, 0.0f);
}

void Tamagotchi::update(Throwings_Gen& _throwings, Score& _score)
{
	if (this->getHitted() == true) {
		if (clock.getElapsedTime().asMilliseconds() > 500) {
			
			assert(img.loadFromFile(""));
			tamagotchi.setTexture(img);

			this->setHitted(false);
		}
	}
	if (_throwings.checkHit(tamagotchi.getGlobalBounds()) == true) {
		assert(img.loadFromFile(""));
		tamagotchi.setTexture(img);
		//_sound.play();
		this->setHitted(true);
		_score.upScore();
		clock.restart();
		//throwing 종류 구별해서 업데이트해주기!
		/*
		if (_throwings == true) {
			assert(img.loadFromFile(""));
			tamagotchi.setTexture(img);
			//_sound.play();
			hitted = true;
			_score.upScore();
			clock.restart();
		}
		else {
			assert(img.loadFromFile(""));
			tamagotchi.setTexture(img);
			//_sound.play();
			hitted = true;
			_score.downScore();
			clock.restart();
		}*/
	}
} 
void Tamagotchi::draw(RenderWindow& _window) {
	_window.draw(tamagotchi);
}
bool Tamagotchi::getHitted(void) {
	return this->hitted;
}
void Tamagotchi::setHitted(bool boolean) {
	this->hitted = boolean;
}