#pragma once
#ifndef SCORE_H
#define SCORE_H
class Score {
private:
	int score;
public:
	Score() {
		score = 0;
	};
	void upScore();
	void downScore();
	int update();
};

#endif