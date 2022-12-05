#pragma once
#ifndef SCOREANDLIFE_H
#define SCOREANDLIFE_H
class ScoreAndLife {
private:
    int score;
    int life;
public:
    ScoreAndLife() {
        score = 0;
        life = 5;
    };
    void upScore();
    void downScore();
    int update();
    int updateLife();
};

#endif
