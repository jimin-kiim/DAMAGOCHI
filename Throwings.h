#pragma once

#ifndef THROWINGS_H
#define THROWINGS_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cassert>
#include <iostream>
#include "Score.h"

using namespace sf;
using namespace std;

class Throwings {
private:
	float x;
	float speed;
	Texture food_img;
	Texture ddong_img;
	Sprite food;
	Sprite ddong;
	Clock clock;
	bool is_food; // Food, Ddong 구분 장치

public:
	bool hit = false;
	bool destroyed = false;
	bool destroyed_hit = false;
	Throwings(float _x, float _speed, bool _is_food)
		: x(_x), speed(_speed), is_food(_is_food)
	{
		if (this->is_food == true) {
			assert(food_img.loadFromFile(""));
			food.setTexture(food_img);
			food.setPosition(_x, 0.0f);
		}
		else if (this->is_food == false) {
			assert(ddong_img.loadFromFile(""));
			ddong.setTexture(food_img);
			ddong.setPosition(_x, 0.0f);
		}
	}
	void update(Score&);
	void draw(RenderWindow&);
	FloatRect getArea();
};

#endif