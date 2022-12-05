#include "ScoreAndLife.h"

void ScoreAndLife::upScore() {
    score += 100;
};
void ScoreAndLife::downScore() {
    if (score > 0) {
        score -= 100;
    }
    life -= 1;
};
int ScoreAndLife::update() {
    return score;
};

int ScoreAndLife::updateLife() {
    return life;
}