#ifndef __UI_H__
#define __UI_H__
#include "tamagotchi.h"
#include "GamePage.h"
class UI
{
private:
  Tamagotchi tamagotchi;
  GamePage gamepage;
 
  enum option
  {
    INTRODUCTION = 1,
    FEED,
    SLEEP,
    GAME,
    EXIT
  };
  static const string baby_tamagotchi;
  static const string baby_tamagotchi_sleeping;
  static const string child_tamagotchi;
  static const string child_tamagotchi_sleeping;
  static const string teen_tamagotchi;
  static const string teen_tamagotchi_sleeping;

public:
  UI(){};
  void loadingView();
  void drawTamagotchi();

  void setTamagotchi();
  void showMainView();
  void introduce();
  void feedTamagotchi();
  int makeTamagotchiGoToBed();
};

#endif
