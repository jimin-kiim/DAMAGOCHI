#pragma once
#ifndef PAGE_H
#define PAGE_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Page {
private:
    int width;
    int height;
    Font font;
public:
    Page() {
        width = 360;
        height = 480;
        RenderWindow window(VideoMode(width, height), "TAMAGOCHI - MINIGAME");
        window.setFramerateLimit(60); //프레임 속도 
        srand((unsigned int)time(NULL));

        if (!font.loadFromFile("img/Roboto-Regular.ttf")) {
            return;
        }
        RectangleShape rec(Vector2f(360, 480));
        rec.setFillColor(Color::White);
        rec.setPosition(0, 0);
    }


    /*
    SoundBuffer buffer;
    if (!buffer.loadFromFile("Roboto-Regular.ttf")) {
        cout << "sound file error" << endl;
    }
    Sound sound(buffer);
    */
};

#endif