#ifndef __UI_H__
#define __UI_H__
#include "tamagotchi.h"
class UI
{
private:
  Tamagotchi tamagotchi;
  enum option
  {
    INTRODUCTION = 1,
    FEED,
    PLAY,
    SLEEP
  };
  static const string baby_tamagotchi;
  static const string child_tamagotchi;
  static const string teen_tamagotchi;

public:
  UI(){};
  void loadingView();

  void setTamagotchi();
  void showMainView();
  void drawTamagotchi();
};

#endif