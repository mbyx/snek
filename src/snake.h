#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

#include <raylib.h>

#include "grid.h"

class Snake {
public:
    enum Direction { North, South, East, West };

    Snake(Vector2 headPosition, Direction direction, Color headColor, Color bodyColor);

    void Draw(Grid& grid);

    void Update(Grid &grid);

    Vector2 headPosition_;
    std::vector<Vector2> bodyPositions_;

private:
    Direction direction_;
    Color headColor_;
    Color bodyColor_;
};

#endif