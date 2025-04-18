#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>

using namespace std;

void rollDice(vector<int> &dice, vector<bool> keepDice)
{
    for (int i = 0; i < 5; i++)
    {
        if (keepDice[i] == false)
        {
            dice[i] = rand() % 6 + 1;
        }
    }
}

int calculateScore(vector<int> dice, int category)
{
    int score = 0;
    int counts[6];
    for (int i = 0; i < 6; i++)
    {
        counts[i] = 0;
    }
    for (int i = 0; i < 5; i++)
    {
        counts[dice[i] - 1]++;
    }
    switch (category)
    {
    case 1 ... 6:
        return counts[category-1]*category;
    case 7:
        sort(counts, counts + 6);
        if (counts[5] < 3)
        {
            return 0;
        }
        else
        {
            for (int i = 0; i < 6; i++)
            {
                score += counts[i] * (i + 1);
            }
            return score;
        }
    case 8:
        sort(counts, counts + 6);
        if (counts[5] < 4)
        {
            return 0;
        }
        else
        {
            for (int i = 0; i < 6; i++)
            {
                score += counts[i] * (i + 1);
            }
            return score;
        }
    case 9:
        sort(counts, counts + 6);
        if (counts[4] == 2 && counts[5] == 3)
        {
            return 25;
        }
        return 0;
    case 10:
        if (counts[0] >= 1 && counts[1] >= 1 && counts[2] >= 1 && counts[3] >= 1)
        {
            return 30;
        }
        if (counts[1] >= 1 && counts[2] >= 1 && counts[3] >= 1 && counts[4] >= 1)
        {
            return 30;
        }
        if (counts[2] >= 1 && counts[3] >= 1 && counts[4] >= 1 && counts[5] >= 1)
        {
            return 30;
        }
        return 0;
    case 11:
        if (counts[0] >= 1 && counts[1] >= 1 && counts[2] >= 1 && counts[3] >= 1 && counts[4] >= 1)
        {
            return 40;
        }
        if (counts[1] >= 1 && counts[2] >= 1 && counts[3] >= 1 && counts[4] >= 1 && counts[5] >= 1)
        {
            return 40;
        }
        return 0;
    case 12:
        for (int i = 0; i < 6; i++)
        {
            if (counts[i] == 5)
            {
                return 50;
            }
        }
        return 0;
    case 13:
        for (int i = 0; i <= 5; i++)
        {
            score += counts[i] * (i + 1);
        }
        return score;
    }
}

int main()
{
    srand(chrono::system_clock::now().time_since_epoch().count());
    int categoryChoice = 1;
    vector<int> scores = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<bool> usedCategories = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> dice = {0, 0, 0, 0, 0};
    vector<bool> keepDice = {0, 0, 0, 0, 0};
    int reroll;
    for (int i = 0; i < 13; i++) //13 - number of turns
    {
        for (int j = 0; j < 2; j++) // 2 - number of rerolls
        {
            rollDice(dice, keepDice);
            cout << "Your dice roll:";
            for (int k = 0; k < 5; k++)
            {
                cout << " " << dice[k];
            }
            cout << "\nChoose which dice to keep: (1 - keep, 0 - reroll): ";
            keepDice.clear();
            for (int l = 0; l < 5; l++)
            {
                    cin >> reroll;
                    while(reroll!=0 and reroll!=1)
                        {
                            cout << "Invalid character. Try again: ";
                            cin >> reroll;
                        }
                    keepDice.push_back(reroll);
            }
        }
        rollDice(dice, keepDice);
        cout << "Your dice:";
        for (int m = 0; m < 5; m++)
        {
            cout << " " << dice[m];
        }
        cout << "\nChoose a scoring category (1-13):";
        cout << "\n+---------------------+----------------------------+-----------------+------------------+\n";
        cout << "|     CATEGORY            |        DESCRIPTION         |   SCORING       | YOUR SCORE      \n";
        cout << "+-------------------------+----------------------------+-----------------+--------------+\n";
        cout << "| (1)Ones                 | Sum of all 1s              | 1 x number of 1s|        " << scores[0] << "         \n";
        cout << "| (2)Twos                 | Sum of all 2s              | 2 x number of 2s|        " << scores[1] << "         \n";
        cout << "| (3)Threes               | Sum of all 3s              | 3 x number of 3s|        " << scores[2] << "         \n";
        cout << "| (4)Fours                | Sum of all 4s              | 4 x number of 4s|        " << scores[3] << "         \n";
        cout << "| (5)Fives                | Sum of all 5s              | 5 x number of 5s|        " << scores[4] << "         \n";
        cout << "| (6)Sixes                | Sum of all 6s              | 6 x number of 6s|        " << scores[5] << "         \n";
        cout << "+-------------------------+----------------------------+-----------------+--------------+\n";
        cout << "| (7)Three of a Kind      | 3 dice same value          | Sum of all dice |        " << scores[6] << "         \n";
        cout << "| (8)Four of a Kind       | 4 dice same value          | Sum of all dice |        " << scores[7] << "         \n";
        cout << "| (9)Full House           | 3 + 2 same value           | 25 points       |        " << scores[8] << "         \n";
        cout << "| (10)Small Straight      | Four sequential dice       | 30 points       |        " << scores[9] << "         \n";
        cout << "| (11)Large Straight      | Five sequential dice       | 40 points       |        " << scores[10] << "         \n";
        cout << "| (12)Yahtzee             | All five dice same         | 50 points       |        " << scores[11] << "         \n";
        cout << "| (13)Chance              | Any combination            | Sum of all dice |        " << scores[12] << "         \n";
        cout << "+-------------------------+----------------------------+-----------------+--------------+\n";

        cin >> categoryChoice;
        while (categoryChoice < 1 || categoryChoice > 13 || usedCategories[categoryChoice - 1])
        {
            cout << "Invalid or already used category. Choose another one: ";
            cin >> categoryChoice;
        }
        usedCategories[categoryChoice - 1] = true;

        scores[categoryChoice - 1] = calculateScore(dice, categoryChoice);
        for (int x = 0; x < 5; x++)
        {
            keepDice[x] = 0;
        }
    }
    int totalScore = 0;
    for (int i = 0; i < 13; i++)
    {
        totalScore += scores[i];
    }
    cout << "Your final score is: " << totalScore << ". Congratulations!";
    return 0;
}
