#include <cstdlib>

#include "food.h"

Food::Food(Vector2 position, Color foodColor) : eaten_(false), position_(position), foodColor_(foodColor) {}

void Food::Draw(Grid& grid) {
    grid.At(position_.x, position_.y) = foodColor_;
}

void Food::Update(Grid& grid, Snake& snake) {
    if (eaten_) {
        position_ = {float(rand() % grid.GetColumns()), float(rand() % grid.GetRows())};
        snake.bodyPositions_.insert(snake.bodyPositions_.begin(), {position_});
        eaten_ = false;
    } else if (snake.headPosition_.x == position_.x && snake.headPosition_.y == position_.y) {
        eaten_ = true;
    }
}