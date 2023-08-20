#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "hangman_art.h"
#include "hangman_words.h"

using namespace std;

int main() {
    cout << hangman_art::logo << endl;

    vector<string> stages = hangman_art::stages;
    vector<string> word_list = hangman_words::word_list;
    string word = word_list[rand() % word_list.size()];

    vector<char> answer;

    cout << "The hanging pole: " << stages[6] << endl;

    for (size_t i = 0; i < word.length(); ++i) {
        answer.push_back('_');
    }

    cout << "You are going to guess this word: ";
    for (char i : answer) {
        cout << i << " ";
    }
    cout << endl;

    int lives = 6;
    int warnings = 3;

    while (std::find(answer.begin(), answer.end(), '_') != answer.end() && lives > 0) {
        char guess;
        cout << "Guess a letter in the word: ";
        cin >> guess;
        cout << endl;

        bool alreadyGuessed = false;
        for (char i : answer) {
            if (i == guess) {
                alreadyGuessed = true;
                break;
            }
        }

        if (alreadyGuessed) {
            if (warnings > 0) {
                --warnings;
            } else {
                --lives;
            }
            cout << "Warning: You have already input '" << guess << "'" << endl;
        } else {
            bool found = false;
            for (size_t i = 0; i < answer.size(); ++i) {
                if (answer[i] == '_' && word[i] == guess) {
                    answer[i] = guess;
                    found = true;
                }
            }
            if (!found) {
                if (guess < 'a' || guess > 'z') {
                    cout << "Please input a single character." << endl;
                } else if (word.find(guess) == string::npos) {
                    cout << "'" << guess << "' is not in the word." << endl;
                    --lives;
                }
            }
        }

        cout << "Progress: ";
        for (char i : answer) {
            cout << i << " ";
        }
        cout << stages[lives] << endl;
    }

    if (lives == 0) {
        cout << "You lose." << endl;
    } else {
        cout << "Congratulations, You Win!" << endl;
    }
    cout << "Word: " << word << endl;

    return 0;
}
