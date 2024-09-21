#include <raylib.h>

#include "grid.h"

Grid::Grid(Vector2 gridSize, Vector2 cellSize, int gridLineSize, Color backgroundColor)
    : gridSize_(gridSize),
        cellSize_(cellSize),
        gridLineSize_(gridLineSize),
        backgroundColor_(backgroundColor) {
    contents_.resize(GetRows() * GetColumns(), Color{0, 0, 0, 255});
}

Color& Grid::At(size_type column, size_type row) {
    return contents_.at(row * GetColumns() + column);
}

void Grid::Fill(Color color) {
    for (size_type row = 0; row != GetRows(); ++row) {
        for (size_type column = 0; column != GetColumns(); ++column) {
            At(column, row) = color;
        }
    }
}

void Grid::Draw() {
    ClearBackground(backgroundColor_);
    for (size_type row = 0; row != GetRows(); ++row) {
        for (size_type column = 0; column != GetColumns(); ++column) {
            Color &cellColor = At(column, row);
            DrawRectangle(
                (gridLineSize_ / 2) + column * cellSize_.x,
                (gridLineSize_ / 2) + row * cellSize_.y,
                cellSize_.x - gridLineSize_,
                cellSize_.y - gridLineSize_,
                cellColor
            );
        }
    }
    Fill({0, 0, 0, 255});
}