#include <iostream>

#include "raylib-cpp.hpp"

#include "resources/icon.h"

#define CLEAR std::cout << "\x1B[2J\x1B[H";

void two_player() {
    std::cout << "players\n";
}

void computer() {
    std::cout << "computer\n";
}

/*int main() {
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
}*/

enum GameState {
    MENU,
    GAME,
    END
};

struct GameData {
    raylib::Vector2 mousePosition;
    raylib::Rectangle rectangle = {};
};

void renderMenu(raylib::Window *window, GameState *state, GameData *data) {
    data->mousePosition = GetMousePosition();

    window->BeginDrawing();

    DrawText("GAME OF PIG", window->GetWidth() / 2 - MeasureText("GAME OF PIG", 40) / 2, window->GetHeight() / 2 - 60, 40, raylib::Color::White());

    window->EndDrawing();
}

int main() {
    int screenWidth = 800;
    int screenHeight = 450;

    raylib::Window window(screenWidth, screenHeight, "GameOfPig");

    window.SetIcon(Image{
        .data = ICON_DATA,
        .width = ICON_WIDTH,
        .height = ICON_HEIGHT,
        .mipmaps = 1,
        .format = ICON_FORMAT});
    window.SetTargetFPS(60);

    window.ClearBackground(raylib::Color::Black());

    GameState state = MENU;
    GameData data = {};

    while (!window.ShouldClose()) {
        switch (state) {
        case MENU:
            renderMenu(&window, &state, &data);
            break;
        case GAME:
            break;
        case END:
            break;
        }
    }
    return 0;
}