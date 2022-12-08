#include <iostream>
#include <unistd.h> // 윈도우에서 할 땐 주석 처리해야 합니다. 
// #include <windows.h> // 윈도우에서 할 땐 주석을 풀어줘야 합니다.
#define MULTILINE_STRING(s) #s
#include "ui.h"
#include "tamagotchi.h"
using namespace std;

const string UI::baby_tamagotchi = "\
            \n\
           ____ \n\
         /     \\\n\
        |       |  \n\
        |       | \n\
         \\_____/  \n\
            \n";

const string UI::baby_tamagotchi_sleeping = "\
            \n\
           ____ \n\
         /     \\...zzZ\n\
        |       |  Sleeping ...\n\
        |       | \n\
         \\_____/  \n\
            \n";

const string UI::child_tamagotchi = "\
            \n\
           ________ \n\
         /          \\\n\
        |っ ‘ ᵕ ‘ C |  \n\
        |           | \n\
        |           | \n\
         \\_________/  \n\
            \n";

const string UI::child_tamagotchi_sleeping = "\
            \n\
           ________ \n\
         /          \\...zzZ\n\
        |っ ᴗ˳ᴗ   C |  Sleeping ...\n\
        |           | \n\
        |           | \n\
         \\_________/  \n\
            \n";

const string UI::teen_tamagotchi = "\
            \n\
            _______ \n\
          /         \\\n\
         |   •‿•    |  \n\
        ┏|          |┛ \n\
         |          | \n\
          \\________/  \n\
            \n";

const string UI::teen_tamagotchi_sleeping = "\
            \n\
            _______ \n\
          /         \\...zzZ\n\
         |   ᴗ˳ᴗ    |  Sleeping ...\n\
        ┏|          |┛ \n\
         |          | \n\
          \\________/  \n\
            \n";

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

    tamagotchi = Tamagotchi(name, introduction);
    cout << "Have a great time with \"" << name << "\" :)";
}

void UI::showMainView()
{
    int flag = 1;
    string name = tamagotchi.getName();
    while (flag)
    {
        drawTamagotchi();
        cout << "1. See "<< name << "'s introduction \n";
        cout << "2. Feed "<< name << " \n";
        cout << "3. Make "<< name << " go to bed \n";
        cout << "4. exit \n";

        int user_input;
        cout << "What are you going to do ? >> ";
        cin >> user_input;

        switch (user_input)
        {
        case INTRODUCTION:
            introduce();
            break;
        case FEED:
            cout << "\"2. Feed Tamagotchi\" selected \n";
            break;
        case SLEEP:
            makeTamagotchiGoToBed();
            break;
        case EXIT:
            flag = 0;
            break;
        default:
            cout << "Wrong Input \n";
        }
    }
}

void UI::drawTamagotchi()
{
    int xp = tamagotchi.getXp();
    if (xp >= 200)
    {
        cout << teen_tamagotchi;
    }
    else if (xp >= 100)
    {
        cout << child_tamagotchi;
    }
    else
    {
        cout << baby_tamagotchi;
    }
}

void UI::introduce()
{
    cout << "Hello! my name is " << tamagotchi.getName() << endl;
    cout << tamagotchi.getIntroduction() << endl;
    cout << "My xp is " << tamagotchi.getXp() << ". Please grow me up!" << endl;
}

void UI::feedTamagotchi()
{
    tamagotchi.increaseXp(50);
}

int UI::makeTamagotchiGoToBed()
{
    int xp = tamagotchi.getXp();
    string name = tamagotchi.getName();
    if (xp >= 200)
    {
        cout << teen_tamagotchi_sleeping;
    }
    else if (xp >= 100)
    {
        cout << child_tamagotchi_sleeping;
    }
    else
    {
        cout << baby_tamagotchi_sleeping;
    }
    cout << "...zzZ\n";
    sleep(1); // 윈도우에서 할 땐 Sleep(3);으로 대문자로 작성해주셔야 합니다 !
     cout << "...zzZ\n";
    sleep(1);
     cout << "...zzZ\n";
     sleep(1);
    cout << "\'"<< name << "\' woke up! (　＾∇＾)\n";
    sleep(1);
    tamagotchi.increaseXp(50);
    return 0;
}