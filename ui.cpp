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
    cout << "다마고치에게 이름을 지어주세요 >>";
    getline(cin, name);

    string user_input;
    cout << name << "의 소개말을 작성해주실래요?  (y/n)>>";
    getline(cin, user_input);

    string introduction;
    if (user_input == "y"){
        cout << name << "의 소개말을 입력해주세요! >>";
        getline(cin, introduction);
        cout << name << "의 소개말 : "<< "\""<< introduction << "\"\n";
    }else{
        introduction = "안녕하세요, " + name + "입니다 :D";
        cout << "기본 소개말로 설정되었습니다.\n";
        cout << name << "의 소개말 : "<< "\""<< introduction << "\"\n";
    }

    Tamagotchi Tamagotchi(name,introduction);
    cout << name << "와 좋은 추억을 만들어보세요 :)";
}

void UI::showMainView(){

}
