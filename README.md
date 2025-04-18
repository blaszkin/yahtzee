
# Yahtzee
Yahtzee game in C++

This is a console-based implementation of the classic game **Yahtzee** in C++.

## How to Play

1. **Rolling Dice:**
   - You will start with 5 dice rolled randomly.
   - After each roll, you can choose which dice to keep and which to reroll. You can roll up to 2 times per turn.

2. **Choosing Categories:**
   - After the final roll, you will choose a category to score for.
   - There are 13 categories in total, including:
     - Ones, Twos, Threes, Fours, Fives, Sixes
     - Three of a Kind, Four of a Kind, Full House, Small Straight, Large Straight, Yahtzee, Chance
   - Each category can only be used once, and the scoring rules are based on the dice roll.

3. **Winning:**
   - The game ends after all 13 categories have been scored.
   - Your final score will be the sum of all your scores from the categories.
### Prerequisites

To run this game, you need:
- A C++ compiler (e.g., GCC or Clang)

### Compilation

1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/blaszkin/yahtzee.git
