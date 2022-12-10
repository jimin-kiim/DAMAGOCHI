#include "studyingGame.h"
#include <unistd.h> // 맥
// #include <windows.h> // 윈도우
#include <algorithm>
#include <random>

using namespace std;
StudyingGame::StudyingGame()
{
    score = 100;
    words = {{"cat", {"This is an animal.", "It's fluffy.", "It's a popular pet."}},
             {"kimchi", {"It's food.", "Its color is red.", "It's korean traditional food."}},
             {"rainbow", {"People usually take pictures when they see it.", "It can be seen after raining.", "Some people say it consists of 7 colors."}}};
    // words.push_back(Resource("cat", {"This is an animal.", "It's fluffy.", "It's a popular pet."}));
    // vector<string> hints = {"This is an animal.", "It's fluffy.", "It's a popular pet."};
    // words.push_back({"cat", hints});
    // words.push_back({"kimchi", {"It's food.", "Its color is red.", "It's korean traditional food."}});
    // words.push_back({"rainbow", {"People usually take pictures when they see it.", "It can be seen after raining.", "Some people say it consists of 7 colors."}});
}
int StudyingGame::selectTargetWord()
{
    random_device rd;
    default_random_engine rng(rd());
    vector<int> options;
    for (int i = 0; i < words.size(); i++)
        options.push_back(i);

    shuffle(options.begin(), options.end(), rng);
    cout << options[0];
    return options[0];
}
int StudyingGame::startGame(int index)
{
    string answer = words[index].word;
    cout << "Please Guess a word. We'll give you 3 chances !\n";
    sleep(1);
    cout << "First hint!\n";
    sleep(1);
    cout << "\n"<< words[index].hints[0] << "\n\n";
    sleep(1);
    cout << "Can you guess the word? \n";
    sleep(1);
    cout << "Please enter your answer\n>>";
    string user_input;
    cin >> user_input;
    if (user_input == answer)
    {
        sleep(1);
        cout << "You got the answer!!  \n";
        sleep(1);
        cout << "As you got the answer right away, there's no deduction !\n\n";
        sleep(1);
        return 0;
    }
    else
    {
        sleep(1);
        cout << "That's not the answer :(  \n";
        sleep(1);
        cout << "We'll give you a second hint \n";
        sleep(1);
        cout << "\n" << words[index].hints[1] << "\n\n";
        sleep(1);
        cout << "Can you guess the word? \n";
        sleep(1);
        cout << "Please enter your answer\n>>";
        cin >> user_input;
        if (user_input == answer)
        {
            sleep(1);
            cout << "You got the answer!!  \n";
            sleep(1);
            cout << "As you got the answer in second try, there's only 30 points deduction !\n\n";
            sleep(1);
            decreaseScore(30);
            return 0;
        }
        else
        {
            sleep(1);
            cout << "Well This is the last chance. \n";
            sleep(1);
            cout << "We'll give you the last hint \n";
            sleep(1);
            cout << "\n" << words[index].hints[2] << "\n\n";
            sleep(1);
            cout << "Can you guess the word? \n";
            sleep(1);
            cout << "Please enter your answer\n>>";
            string user_input;
            cin >> user_input;
            if (user_input == answer)
            {
                sleep(1);
                cout << "You got the answer!!  \n";
                sleep(1);
                cout << "As you gained 50 points !\n\n";
                sleep(1);
                decreaseScore(50);
                return 0;
            }
            else
            {
                sleep(1);
                cout << "You lost the game :( ...  \n";
                sleep(1);
                cout << "The answer was " << answer << "  \n";
                sleep(1);
                cout << "As you didn't get the answer you only get 30 points !\n\n";
                sleep(1);
                decreaseScore(70);
                return 0;
            }
        }
    }
}
void StudyingGame::decreaseScore(int deduction)
{
    score -= deduction;
}
int StudyingGame::getScore()
{
    cout << "Your final score is " << score << "\n";
    return score;
}