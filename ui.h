#include "tamagotchi.h"
class UI
{
private:
    Tamagotchi tamagotchi;
public:
    UI(){};
    void setTamagotchi();
    void showMainView();
    void introduce();
};