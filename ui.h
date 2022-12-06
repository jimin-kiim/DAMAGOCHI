#include "tamagotchi.h"
class UI
{
private:
    enum option {INTRODUCTION = 1, FEED, PLAY, SLEEP };
  static const string baby_tamagotchi;
  static const string child_tamagotchi;
  static const string teen_tamagotchi;

public:
    UI(){};
    void setTamagotchi();
    void showMainView();
    void drawBabyTamagotchi();
};