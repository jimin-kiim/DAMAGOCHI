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
    int start_flag = 0;
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
        if (start_flag == 0) {
            startPage(_window, _font);
            start_flag = 1;
        }
        throwings.update(score);
        tamagotchi.update(throwings, score);
        _window.clear();
        _window.draw(rec);
        tamagotchi.draw(_window);
        throwings.draw(_window);
        cur_score = score.update();
        cur_life = score.updateLife();

        clock_t end = clock();
        int time = (end - score.getStart()) / 1000;
        string nuggim = "";
        if (time % 10 == 0 && time != 0) {
            nuggim = "!!!!!!!!";
            textScore.setFillColor(Color::Green);
            score.upGap(time / 10);
            textgap.setFont(font);
            textgap.setFillColor(Color::Green);
            textgap.setPosition(100.0f, 200.0f);
            textgap.setCharacterSize(30);
            textgap.setString(" Score X " + to_string((time / 10 + 1)) + "!!!!");
            _window.draw(textgap);
        }
        textScore.setString("Score : " + to_string(cur_score) + "\t\t\t\t\t" + to_string(time) + nuggim);
        textLife.setString("\nLife : " + to_string(cur_life));
        textScore.setString("Score : " + to_string(cur_score));
        textLife.setString("\nLife : " + to_string(cur_life));
        _window.draw(textScore);
        _window.draw(textLife);

        if (cur_life <= 0) {
            //다마고치 상태 업데이트
            endPage(_window, _font);
        }
        _window.display();
    }
};

void GamePage::startPage(RenderWindow& _window, Font& _font)
{
    Text textStart;
    Texture texture;
    Sprite background;
    _window.clear();
    //assert(texture.loadFromFile("img/game_intro.png"));
    //background.setTexture(texture);
    _window.draw(background);

    
    RectangleShape recStart(Vector2f(360, 480));
    recStart.setFillColor(Color::Black);
    recStart.setPosition(0, 0);
    _window.draw(recStart);

    textStart.setFont(_font);
    textStart.setFillColor(Color::White);
    textStart.setPosition(70.0f, 170.0f);
    textStart.setCharacterSize(45);
    textStart.setString("Game Start");

    _window.draw(textStart);
    _window.display();
    sleep(milliseconds(2000));

}

void GamePage::endPage(RenderWindow& _window, Font& _font)
{
    Text textEnd;
    Texture texture;
    Sprite icon;
    _window.clear();

    RectangleShape recEnd(Vector2f(360, 480));
    recEnd.setFillColor(Color::Black);
    recEnd.setPosition(0,0);
    _window.draw(recEnd);
    if (cur_score >= 1000) {
        assert(texture.loadFromFile("img/nice_over.png"));
    }
    else if (0 <= cur_score < 1000) {
        assert(texture.loadFromFile("img/bad_over.png"));
    }
    icon.setTexture(texture);
    icon.setPosition(90.0f, 90.0f);

    _window.draw(icon);
    textEnd.setFont(_font);
    textEnd.setFillColor(Color::Red);
    textEnd.setPosition(80.0f, 160.0f);
    textEnd.setCharacterSize(45);
    textEnd.setString("\n\n\n Bye Bye");

    _window.draw(textEnd);
    _window.display();
    sleep(milliseconds(2000));
    _window.close();

}
int GamePage::getScore(void) {
    return this->cur_score;
}