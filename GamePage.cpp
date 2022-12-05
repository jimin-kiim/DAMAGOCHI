#include "GamePage.h"

int GamePage::fontCheck(Font& font, string fontName) {
    if (!font.loadFromFile(fontName)) {
        return -1;
    }
}

void GamePage::rectangle(RectangleShape& _rec) {
    _rec.setFillColor(Color::Black);
    _rec.setPosition(0, 0);
}

void GamePage::gameStart() {
    gameStart(*window, rec, font);
}

void GamePage::gameStart(RenderWindow& _window, RectangleShape& _rec,Font& _font)
{
    _window.setFramerateLimit(60);

    srand((unsigned int)time(NULL));

    if (!font.loadFromFile("Roboto-Regular.ttf")) {
        return;
    }
    rectangle(_rec);

    textScore.setFont(_font);
    textScore.setFillColor(Color::White);
    textScore.setPosition(0.0f, 0.0f);
    textScore.setCharacterSize(15);

    textLife.setFont(_font);
    textLife.setFillColor(Color::Red);
    textLife.setPosition(0.0f, 0.0f);
    textLife.setCharacterSize(15);
    while (_window.isOpen())
    {
        Event event;
        while (_window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                _window.close();
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
        _window.clear();
        _window.draw(rec);
        tamagotchi.draw(_window);
        throwings.draw(_window);
        cur_score = score.update();
        cur_life = score.updateLife();
        textScore.setString("Score : " + to_string(cur_score));
        textLife.setString("\nLife : " + to_string(cur_life));
        _window.draw(textScore);
        _window.draw(textLife);

        if (cur_life <= 0) {
            //다마고치 상태 업데이트
            endPage(_window, _font);
            sleep(milliseconds(2000));
            _window.close();
        }
        _window.display();
    }
};

void GamePage::endPage(RenderWindow& _window, Font& _font)
{
    _window.clear();

    RectangleShape recEnd(Vector2f(360, 480));
    recEnd.setFillColor(Color::Red);
    recEnd.setPosition(0,0);
    _window.draw(recEnd);

    textEnd.setFont(_font);
    textEnd.setFillColor(Color::White);
    textEnd.setPosition(80.0f, 200.0f);
    textEnd.setCharacterSize(45);
    textEnd.setString("Game End");

    _window.draw(textEnd);
    _window.display();

}
int GamePage::getScore(void) {
    return this->cur_score;
}