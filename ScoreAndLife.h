#pragma once
#ifndef SCOREANDLIFE_H
#define SCOSCOREANDLIFE_H
#include<time.h>
class ScoreAndLife {
private:
	int score;
	int life;
	clock_t start;
	int gap;
public:
	ScoreAndLife() {
		score = 0;
		gap = 100;
		life = 5;
		start = clock();
	};
	void upScore();
	void downScore();
	void upTime();
	int update();
	int updateLife();
	int updateTime();
	void upGap(int p);
	clock_t getStart();
};

#endif