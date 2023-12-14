#include <iostream>

#define CLEAR std::cout << "\x1B[2J\x1B[H";

void two_player() {
    std::cout << "players\n";
}

void computer() {
    std::cout << "computer\n";
}

int main() {
    std::cout << "Welcome to the game of pig. The object of this game is to be the first player to reach 100. This is done through the rolling of a six-sided die. On a players turn they can either roll the die or stay. On each roll the number is added to their total round score, they keep re rolling as long as they like. The twist is that if they roll a one, their round score is nothing and the other player begins their turn. Staying adds the players round score to their total score, then moves play to the other player.\n\n";

    std::cout << "Now you need to select a gamemode. The Options are:\n\n(2) player\n(C)omputer\n";

    std::string input_mode;
    std::cin >> input_mode;

    CLEAR;

    if (input_mode[0] == 'c') {
        computer();
    } else if (input_mode[0] == '2') {
        two_player();
    } else {
        std::cout << "Invalid Choice\n";
    }

    return 0;
}