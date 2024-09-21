#ifndef FOOD_H
#define FOOD_H

#include <raylib.h>

#include "grid.h"
#include "snake.h"

struct Food {
    Food(Vector2 position, Color foodColor);

    void Update(Grid &grid, Snake &snake);
    void Draw(Grid& grid);

    bool eaten_;
    Vector2 position_;
    Color foodColor_;
};

#endif