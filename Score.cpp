#include "Score.h"

void Score::upScore() {
	score += 100;
};
void Score::downScore() {
	score -= 100;
};
int Score::update() {
	return score;
};