#ifndef GRID_H
#define GRID_H

#include <vector>

class Grid {
public:
    using size_type = std::vector<Color>::size_type;

    Grid(Vector2 gridSize, Vector2 cellSize, int gridLineSize, Color backgroundColor);

    size_type GetRows() const { return gridSize_.y / cellSize_.y; }

    size_type GetColumns() const { return gridSize_.x / cellSize_.x; }

    Color &At(size_type column, size_type row);

    void Fill(Color color);

    void Draw();

private:
    std::vector<Color> contents_;
    Vector2 gridSize_;
    Vector2 cellSize_;
    int gridLineSize_;
    Color backgroundColor_;
};

#endif