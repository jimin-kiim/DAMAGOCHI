#include <iostream>
#include "tamagotchi.h"
using namespace std;

Tamagotchi::Tamagotchi(string name, string introduction)
{
    this->name = name;
    this->introduction = introduction;
    this->xp = 0;
}