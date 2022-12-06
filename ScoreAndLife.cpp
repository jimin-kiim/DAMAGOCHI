#include "ScoreAndLife.h"
#include<math.h>

void ScoreAndLife::upScore() {
	score += gap;
};
void ScoreAndLife::downScore() {
	if (score - gap <= 0) {
		score = 0;
	}
	else {
		score -= gap;
	}
	life -= 1;
};

int ScoreAndLife::update() {
	return score;
};
int ScoreAndLife::updateLife() {
	return life;
};

void ScoreAndLife::upGap(int p) {
	gap = 100 * (p + 1);
}
clock_t ScoreAndLife::getStart() {
	return start;
}