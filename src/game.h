#include <cstdlib>
#include <string>

#include <raylib.h>

#include "grid.h"
#include "snake.h"
#include "food.h"

int StartGame(Vector2 screenSize, Vector2 cellSize, std::string title) {
    Grid grid(screenSize, cellSize, 2, WHITE);
    Vector2 center = {float(grid.GetColumns() / 2), float(grid.GetRows() / 2)};    
    
    Snake snake(center, Snake::Direction::North, RED, GREEN);

    Vector2 randomPosition = {float(rand() % grid.GetColumns()), float(rand() % grid.GetRows())};
    Food food(randomPosition, BLUE);

    InitWindow(screenSize.x, screenSize.y, title.c_str());
    SetTargetFPS(20);

    while (!WindowShouldClose()) {
        BeginDrawing();

        snake.Draw(grid);
        snake.Update(grid);

        food.Draw(grid);
        food.Update(grid, snake);
        
        grid.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}