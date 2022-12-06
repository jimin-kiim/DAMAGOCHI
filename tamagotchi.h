
#ifndef __TAMAGOTCHI_H__ 
#define __TAMAGOTCHI_H__ 

#include <iostream>
using namespace std;
class Tamagotchi
{
    string name;
    string introduction;
    int xp;

public:
    Tamagotchi(){};
    Tamagotchi(string, string);
    string getName() { return this->name };
    string getIntroduction() { return this->introduction };
    int getXp() { return this->xp };
};

#endif