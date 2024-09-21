#include "game.h"

const Vector2 SCREEN_SIZE({1280, 720});
const Vector2 CELL_SIZE({20, 20});

int main() {
    return StartGame(SCREEN_SIZE, CELL_SIZE, "snek");
}