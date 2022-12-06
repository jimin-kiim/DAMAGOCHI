#include "ui.h"
#include "tamagotchi.h"

int main()
{
    UI ui;
    Tamagotchi tamagotchi;

    ui.setTamagotchi();
    ui.showMainView();
    return 0;
}