#pragma once
#ifndef STUDYING_GAME_H
#define STUDYING_GAME_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Resource
{
    string word;
    vector<string> hints;
} typedef Resource;

class StudyingGame
{
private:
    int score;
    vector<Resource> words;

public:
    StudyingGame();
    int selectTargetWord();
    int startGame(int);
    void decreaseScore(int);
    int getScore();
};

#endif