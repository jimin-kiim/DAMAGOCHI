
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
};

#endif