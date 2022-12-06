#include "tamagotchi.h"
class UI
{
private:
    enum option {INTRODUCTION = 1, FEED, PLAY, SLEEP };
public:
    UI(){};
    void setTamagotchi();
    void showMainView();
    void drawBabyTamagotchi();
};