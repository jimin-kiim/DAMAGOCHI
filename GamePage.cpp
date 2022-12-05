#include "GamePage.h"

int GamePage::fontCheck(Font& font, string fontName) {
    if (!font.loadFromFile(fontName)) {
        return -1;
    }
}

void GamePage::rectangle(RectangleShape&) {
    rec.setFillColor(Color::White);
    rec.setPosition(0, 0);
}

void GamePage::gameStart(RenderWindow& window)
{
    window.setFramerateLimit(60);

    srand((unsigned int)time(NULL));

    if (fontCheck(font, "Roboto - Regular.ttf") == -1) {
        return;
    }
    rectangle(rec);

    textScore.setFont(font);
    textScore.setFillColor(Color::Black);
    textScore.setPosition(0.0f, 0.0f);
    textScore.setCharacterSize(15);

    textLife.setFont(font);
    textLife.setFillColor(Color::Red);
    textLife.setPosition(0.0f, 0.0f);
    textLife.setCharacterSize(15);

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
                    tamagotchi.moveLeft();
                }
                else if (Keyboard::isKeyPressed(Keyboard::Right) == true) {
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
}