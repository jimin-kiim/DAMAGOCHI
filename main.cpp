#include <SFML/Graphics.hpp>
#include "Tamagotchi.h"
#include "Throwings.h"
#include "Throwings_Gen.h"
#include "ScoreAndLife.h"
using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode(360, 480), "TAMAGOTCHI - MINIGAME");
    window.setFramerateLimit(60); //프레임 속도 제한

    srand((unsigned int)time(NULL));
    Font font;
    if (!font.loadFromFile("Roboto-Regular.ttf")) {
        return -1;
    }
    /*
    SoundBuffer buffer;
    if (!buffer.loadFromFile("Roboto-Regular.ttf")) {
        cout << "sound file error" << endl;
    }
    Sound sound(buffer);
    */

    RectangleShape rec(Vector2f(360, 480));
    rec.setFillColor(Color::White);
    rec.setPosition(0, 0);


    Tamagotchi tamagotchi;
    Throwings_Gen throwings;
    ScoreAndLife score;
    Text textScore;
    Text textLife;

    textScore.setFont(font);
    textScore.setFillColor(Color::Black);
    textScore.setPosition(0.0f, 0.0f);
    textScore.setCharacterSize(15);

    textLife.setFont(font);
    textLife.setFillColor(Color::Red);
    textLife.setPosition(0.0f, 0.0f);
    textLife.setCharacterSize(15);
    int cur_score;
    int cur_life;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyPressed:
                if (Keyboard::isKeyPressed(Keyboard::Left) == true) {
                    //¥Ÿ∏∂∞Ìƒ° øﬁ¬ ¿∏∑Œ øÚ¡˜¿Ã∞‘ «œ±‚
                    tamagotchi.moveLeft();
                }
                else if (Keyboard::isKeyPressed(Keyboard::Right) == true) {
                    //¥Ÿ∏∂∞Ìƒ° ø¿∏•¬ ¿∏∑Œ øÚ¡˜¿Ã∞‘ «œ±‚
                    tamagotchi.moveRight();
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
        cur_life = score.updateLife();
        textScore.setString("Score : " + to_string(cur_score));
        textLife.setString("\nLife : " + to_string(cur_life));
        window.draw(textScore);
        window.draw(textLife);

        if (cur_life <= 0) {
            //다마고치 상태 업데이트
            window.close();
        }
        window.display();
    }

    return 0;
}