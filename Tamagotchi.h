#pragma once
#ifndef DAMAGOCHI_H
#define DAMAGOCHI_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cassert>
#include <iostream>
#include "Throwings.h"
#include "Throwings_Gen.h"
using namespace sf;
using namespace std;

class Tamagotchi {
private:
	Texture img;
	Sprite tamagotchi;
	int hit_time;
	Clock clock;
	bool hitted;
public:
	Tamagotchi() {
		assert(img.loadFromFile("player.png"));
		tamagotchi.setTexture(img);
		tamagotchi.setPosition(180.0f - 15.0f, 480.0f - 44.0f);

		hitted = false;
		hit_time = 0;
	}
	void moveLeft(void);
	void moveRight(void);
	void update(Throwings_Gen& _throwings, Score& _score);
	void draw(RenderWindow&);
	bool getHitted(void);
	void setHitted(bool);
};

#endif