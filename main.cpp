#include <SFML/Graphics.hpp>
#include "Tamagotchi.h"
#include "Throwings.h"
#include "Throwings_Gen.h"
#include "Score.h"
using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode(360,480), "TAMAGOTCHI - MINIGAME");
    window.setFramerateLimit(60); //프레임 속도 제한
    
    srand((unsigned int)time(NULL));
    Font font;
    if (!font.loadFromFile("")) {
        return -1;
    }

    SoundBuffer buffer;
    if (!buffer.loadFromFile("")) {
        cout << "sound file error" << endl;
    }
    Sound sound(buffer);

    RectangleShape rec(Vector2f(360, 480));
    rec.setFillColor(Color::White);
    rec.setPosition(0, 0);


    Tamagotchi tamagotchi;
    Throwings_Gen throwings;
    Score score;
    Text text;
    text.setFont(font);
    text.setFillColor(Color::Black);
    text.setPosition(0.0f, 0.0f);
    text.setCharacterSize(15);
    int cur_score;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyPressed:
                if (Keyboard::isKeyPressed(Keyboard::Left) == true) {
                    //다마고치 왼쪽으로 움직이게 하기
                }
                else if (Keyboard::isKeyPressed(Keyboard::Right) == true) {
                    //다마고치 오른쪽으로 움직이게 하기
                }
                break;
            default:
                break;
            }
        }
        throwings.update(score);
        tamagotchi.update(throwings, score);
        window.clear();
        window.draw(rec);
        tamagotchi.draw(window);
        throwings.draw(window);
        cur_score = score.update();
        text.setString(to_string(cur_score));
        window.draw(text);

        if (cur_score <= 0) {
            window.close();
        }
        window.display();
    }

    return 0;
}