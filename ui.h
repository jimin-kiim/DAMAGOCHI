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
    SLEEP,
    MUSIC,
    EXIT
  };
  static const string baby_tamagotchi;
  static const string baby_tamagotchi_sleeping;
  static const string baby_tamagotchi_listening_to_music1;
  static const string baby_tamagotchi_listening_to_music2;
  static const string child_tamagotchi;
  static const string child_tamagotchi_sleeping;
  static const string child_tamagotchi_listening_to_music1;
  static const string child_tamagotchi_listening_to_music2;
  static const string teen_tamagotchi;
  static const string teen_tamagotchi_sleeping;
  static const string teen_tamagotchi_listening_to_music1;
  static const string teen_tamagotchi_listening_to_music2;

public:
  UI(){};
  void drawTamagotchi();

  void setTamagotchi();
  void showMainView();
  void introduce();
  int feedTamagotchi();
  int makeTamagotchiGoToBed();
  int makeTamagotchiEnjoyMusic();
};

#endif
