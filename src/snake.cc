#include <cmath>
#include <iostream>

#include "snake.h"

Snake::Snake(Vector2 headPosition, Direction direction, Color headColor, Color bodyColor)
    : headPosition_(headPosition), bodyPositions_({}), direction_(direction), headColor_(headColor), bodyColor_(bodyColor) {}

void Snake::Draw(Grid &grid) {
    grid.At(headPosition_.x, headPosition_.y) = headColor_;
    for (std::vector<Vector2>::iterator iter = bodyPositions_.begin(); iter != bodyPositions_.end(); ++iter) {
        Vector2 bodyPosition = *iter;
        grid.At(bodyPosition.x, bodyPosition.y) = bodyColor_;
    }
}

void Snake::Update(Grid &grid) {
    if (bodyPositions_.size() != 0) {
        bodyPositions_.pop_back();
        bodyPositions_.insert(bodyPositions_.begin(), {headPosition_});
    }
    
    switch (GetKeyPressed()) {
        case KEY_UP:
            direction_ = North;
            break;
        case KEY_DOWN:
            direction_ = South;
            break;
        case KEY_LEFT:
            direction_ = West;
            break;
        case KEY_RIGHT:
            direction_ = East;
            break;
    }

    switch (direction_) {
        case North:
            headPosition_.y -= 1;
            break;
        case South:
            headPosition_.y += 1;
            break;
        case East:
            headPosition_.x += 1;
            break;
        case West:
            headPosition_.x -= 1;
            break;
    }

    if (headPosition_.x < 0) headPosition_.x += grid.GetColumns();
    if (headPosition_.y < 0) headPosition_.y += grid.GetRows();

    headPosition_.x = int(headPosition_.x) % grid.GetColumns();
    headPosition_.y = int(headPosition_.y) % grid.GetRows();

    for (std::vector<Vector2>::iterator iter = bodyPositions_.begin(); iter != bodyPositions_.end(); ++iter) {
        Vector2 bodyPosition = *iter;
        if (bodyPosition.x == headPosition_.x && bodyPosition.y == headPosition_.y) {
            std::cout << "You lost!" << std::endl;
        }
    }
}