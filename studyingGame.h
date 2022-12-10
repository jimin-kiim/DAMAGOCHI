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
    // Resource(string _word, vector<string> _hints) : word(_word), hints(_hints){};
} typedef Resource;

class StudyingGame
{
private:
    int score;
    vector<Resource> words;

    // vector<Resource>  words = {{"cat", {"This is an animal.", "It's fluffy.", "It's a popular pet."}}};

public:
    StudyingGame();
    int selectTargetWord();
    int startGame(int);
    void decreaseScore(int);
    int getScore();
};

#endif