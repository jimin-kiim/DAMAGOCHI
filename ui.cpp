#include <iostream>
#define MULTILINE_STRING(s) #s
#include "ui.h"
#include "tamagotchi.h"
using namespace std;

void UI::setTamagotchi()
{
    string logo = "\
                                                                        \n\
 _____   _     __  __     _     ____   ___  _____  ____  _   _  ___ \n\
|_   _| / \\   |  \\/  |   / \\   / ___| / _ \\|_   _|/ ___|| | | ||_ _|\n\
  | |  / _ \\  | |\\/| |  / _ \\ | |  _ | | | | | | | |    | |_| | | | \n\
  | | / ___ \\ | |  | | / ___ \\| |_| || |_| | | | | |___ |  _  | | | \n\
  |_|/_/   \\_\\|_|  |_|/_/   \\_\\\\____| \\___/  |_|  \\____||_| |_||___|\n\
                                                                    \n\
                                                                    \n";

    string name;
    cout << logo;
    cout << "Please name Tamagotchi >> ";
    getline(cin, name);

    string user_input;
    cout << "Would you like to set the introduction of \"" << name << "\"?  (y/n) >> ";
    getline(cin, user_input);

    string introduction;
    if (user_input == "y")
    {
        cout << "Please enter the introductory words for \"" << name << "\" >> ";
        getline(cin, introduction);
        cout << "\n"
             << "Introduction of \"" << name << "\": \"" << introduction << "\"\n\n";
    }
    else
    {
        introduction = "Hi, I'm " + name + " :D";
        cout << "Basic introduction is set. \n";
        cout << "\n"
             << "Introduction of \"" << name << "\": \"" << introduction << "\"\n\n";
    }

    Tamagotchi Tamagotchi(name, introduction);
    cout << "Have a great time with \"" << name << "\" :)";
}

void UI::showMainView()
{

    drawBabyTamagotchi();

    cout << "1. See Tamagotchi's introduction \n";
    cout << "2. Feed Tamagotchi \n";
    cout << "3. Play with Tamagotchi \n";
    cout << "4. Make Tamagotchi a bed \n";

    int user_input;
    cout << "What are you going to do ? >> ";
    cin >> user_input;

    switch (user_input)
    {
    case INTRODUCTION:
        cout << "\"1. See Tamagotchi's introduction \" selected \n";
        break;
    case FEED:
        cout << "\"2. Feed Tamagotchi\" selected \n";
        break;
    case PLAY:
        cout << "\"3. Play with Tamagotchi\" selected \n";
        break;
    case SLEEP:
        cout << "\"4. Make Tamagotchi a bed\" selected \n";
    default:
        cout << "Wrong Input \n";
    }
}

void UI::drawBabyTamagotchi()
{
    string baby_tamagotchi = "\
            \n\
           ____ \n\
         /     \\\n\
        |       |  \n\
        |       | \n\
         \\_____/  \n\
            \n";

    cout << baby_tamagotchi;
}