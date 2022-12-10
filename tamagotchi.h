
#ifndef __TAMAGOTCHI_H__
#define __TAMAGOTCHI_H__

#include <iostream>
using namespace std;
class Tamagotchi
{
private:
    string name;
    string introduction;
    int xp;

public:
    Tamagotchi(){};
    Tamagotchi(string, string);
    int getXp() { return this->xp; };
    string getName() { return this->name; };
    string getIntroduction() { return this->introduction; };
    void increaseXp(int xp);
};

#endif