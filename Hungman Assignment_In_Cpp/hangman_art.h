#ifndef HANGMAN_ART_H
#define HANGMAN_ART_H

#include <vector>
#include <string>

namespace hangman_art {
    const std::vector<std::string> stages = {
        R"(
  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========
)",
        R"(
  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========
)",
        R"(
  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========
)",
        R"(
  +---+
  |   |
  O   |
 /|   |
      |
      |
=========
)",
        R"(
  +---+
  |   |
  O   |
  |   |
      |
      |
=========
)",
        R"(
  +---+
  |   |
  O   |
      |
      |
      |
=========
)",
        R"(
  +---+
  |   |
      |
      |
      |
      |
=========
)"
    };

    const std::string logo = R"(
 _
| |
| |__   __ _ _ __   __ _ _ __ ___   __ _ _ __
| '_ \ / _` | '_ \ / _` | '_ ` _ \ / _` | '_ \
| | | | (_| | | | | (_| | | | | | | (_| | | | |
|_| |_|\__,_|_| |_|\__, |_| |_| |_|\__,_|_| |_|
                    __/ |
                   |___/
)";
}

#endif // HANGMAN_ART_H
