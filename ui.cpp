#include <iostream>
// #include <unistd.h> // 맥
#include <windows.h> // 윈도우
#define MULTILINE_STRING(s) #s
#include "ui.h"
#include "tamagotchi.h"
#include <string>
#include "GamePage.h"
using namespace std;

const string UI::baby_tamagotchi = "\n\
\n\
                                  \n\
                                  \n\
                ____              \n\
              /     \\             \n\
             |       |            \n\
             |       |            \n\
              \\_____/              \n\
==================================\n\
\n";

const string UI::baby_tamagotchi_sleeping = "\
            \n\
            \n\
           ____ \n\
         /     \\...zzZ\n\
        |       |  Sleeping ...\n\
        |       | \n\
         \\_____/  \n\
==================================\n\
            \n";

const string UI::baby_tamagotchi_listening_to_music1 = "\
            \n\
            \n\
           ____ \n\
         /     \\         ♩\n\
        |       |            ♪\n\
        |       | ♫\n\
         \\_____/    ♬\n\
==================================\n\
            \n";

const string UI::baby_tamagotchi_listening_to_music2 = "\
            \n\
                       ♬\n\
           ____ \n\
    ♩     /     \\         \n\
         |       |   ♪         \n\
         |       |        ♫\n\
          \\_____/    \n\
==================================\n\
            \n";

const string UI::child_tamagotchi = "\
            \n\
            \n\
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
            \n\
           ________ \n\
         /          \\...zzZ\n\
        |っ ᴗ˳ᴗ   C |  Sleeping ...\n\
        |           | \n\
        |           | \n\
         \\_________/  \n\
==================================\n\
            \n";

const string UI::child_tamagotchi_listening_to_music1 = "\
            \n\
            \n\
           ________ \n\
         /          \\      ♩\n\
        |っ ‘ ᵕ ‘  C |        ♪\n\
        |           | \n\
        |           | ♫\n\
         \\_________/    ♬\n\
==================================\n\
            \n";
const string UI::child_tamagotchi_listening_to_music2 = "\
            \n\
                           ♪\n\
           ________ \n\
         /          \\ ♩\n\
        |っ ‘ ᵕ ‘  C |        \n\
        |           | \n\
        |           |           ♫\n\
         \\_________/       ♬\n\
==================================\n\
            \n";

const string UI::teen_tamagotchi = "\
            \n\
            \n\
            _______ \n\
          /         \\\n\
         |   •‿•    |  \n\
        ┏|          |┛ \n\
         |          | \n\
          \\________/  \n\
==================================\n\
            \n";

const string UI::teen_tamagotchi_sleeping = "\
            \n\
            _______ \n\
          /         \\...zzZ\n\
         |   ᴗ˳ᴗ    |  Sleeping ...\n\
        ┏|          |┛ \n\
         |          | \n\
          \\________/  \n\
==================================\n\
            \n";

const string UI::teen_tamagotchi_listening_to_music1 = "\
            \n\
            _______    ♩\n\
          /         \\    \n\
         |   •‿•    | ♪      \n\
        ┏|          |┛ \n\
         |          |           ♫\n\
          \\________/        ♬\n\
==================================\n\
            \n";
const string UI::teen_tamagotchi_listening_to_music2 = "\
            \n\
            _______ \n\
          /         \\    ♩\n\
         |   •‿•    |       ♪\n\
        ┏|          |┛ \n\
         |          | ♫\n\
          \\________/   ♬\n\
==================================\n\
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
    system("cls");
    cout << "Have a great time with \"" << name << "\" :)";
}

void UI::showMainView()
{
    int flag = 1;
    string name = tamagotchi.getName();
    while (flag)
    {
        drawTamagotchi();
        cout << "==================================\n";
        cout << "1. See " << name << "'s introduction \n";
        cout << "2. Feed " << name << " \n";
        cout << "3. Make " << name << " go to bed \n";
        cout << "4. Make " << name << " enjoy music \n";
        cout << "5. exit \n";
        cout << "==================================\n";
        int user_input;
        cout << "What are you going to do ? >> ";
        cin >> user_input;
        system("cls");
        switch (user_input)
        {
        case INTRODUCTION:
            cout << "==================================\n";
            introduce();
            break;
        case FEED:
            cout << "==================================\n";
            feedTamagotchi();
            break;
        case SLEEP:
            cout << "==================================\n";
            makeTamagotchiGoToBed();
            break;
        case MUSIC:
            cout << "==================================\n";
            makeTamagotchiEnjoyMusic();
            break;
        case EXIT:
            flag = 0;
            break;
        default:
            cout << "==================================\n";
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
    string name = tamagotchi.getName();
    cout << "   Hello! my name is " << name << endl;
     Sleep(1000);
    // sleep(1);
    cout << "   " << tamagotchi.getIntroduction() << endl;
    Sleep(1000);
    // sleep(1);
    cout << "   My xp is " << tamagotchi.getXp() << ". Please grow me up!\n"
         << endl;
     Sleep(1000);
    // sleep(1);

    cout << "\'" << name << "\' got more 50XP!\n";
    cout << "==================================\n";
    tamagotchi.increaseXp(50);
}

int UI::feedTamagotchi()
{
    GamePage gamepage;
    gamepage.gameStart();
    int score = gamepage.getScore();
    string name = tamagotchi.getName();
    cout << "==================================\n";
    Sleep(1000);
    // sleep(1);
    cout << "\'" << name << "\' scored " << score << "\n";
    Sleep(1000);
    // sleep(1);
    cout << "\'" << name << "\' increased " << score/10 << "XP\n";
    cout << "==================================\n";
    tamagotchi.increaseXp(score / 10);
    return 0;
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
    Sleep(1000); // 윈도우에서 할 땐 Sleep(1000); 맥에선 sleep(1);으로 작성해주셔야 합니다 !
    // sleep(1);
    cout << "...zzZ\n";
     Sleep(1000);
    // sleep(1);
    cout << "...zzZ\n";
     Sleep(1000);
    // sleep(1);
    cout << "\'" << name << "\' woke up! :D \n";
    Sleep(1000);
    // sleep(1);
    system("cls");
    cout << "\'" << name << "\' is now relaxed and got more 50XP!\n";
    cout << "==================================\n";
    tamagotchi.increaseXp(50);
    return 0;
}

int UI::makeTamagotchiEnjoyMusic()
{
    int xp = tamagotchi.getXp();
    string name = tamagotchi.getName();
    if (xp >= 200)
    {
        cout << teen_tamagotchi_listening_to_music1;
         Sleep(1000);
         system("cls");
         cout << teen_tamagotchi_listening_to_music2;
         Sleep(1000);
         system("cls");
         cout << teen_tamagotchi_listening_to_music1;
         Sleep(1000);
         system("cls");
          cout << teen_tamagotchi_listening_to_music2;
    }
    else if (xp >= 100)
    {
        cout << child_tamagotchi_listening_to_music1;
         Sleep(1000);
         system("cls");
         cout << child_tamagotchi_listening_to_music2;
         Sleep(1000);
         system("cls");
         cout << child_tamagotchi_listening_to_music1;
         Sleep(1000);
         system("cls");
         cout << child_tamagotchi_listening_to_music2;
    }
    else
    {
        cout << baby_tamagotchi_listening_to_music1;
         Sleep(1000);
         system("cls");
         cout << baby_tamagotchi_listening_to_music2;
         Sleep(1000);
         system("cls");
         cout << baby_tamagotchi_listening_to_music1;
         Sleep(1000);
         system("cls");
          cout << baby_tamagotchi_listening_to_music2;
    }

    system("cls");
    cout << "\'" << name << "\' is now relaxed and got more 50XP!\n";
    cout << "==================================\n";
    tamagotchi.increaseXp(50);
    return 0;
}