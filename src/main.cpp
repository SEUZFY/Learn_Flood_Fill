#include "Learn_Flood_Fill.hpp"

int main() {
    const std::vector<std::vector<double>> grid{
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0} };

    const std::vector<std::vector<double>> solution_left_grid{
        {1, 1, 1, 1, 0},
        {1, 1, 1, 0, 0},
        {1, 1, 1, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 0} };

    const std::vector<std::vector<double>> solution_right_grid{
        {0, 0, 0, 1, 1},
        {0, 0, 1, 1, 1},
        {0, 0, 1, 1, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1} };

    std::vector<std::vector<double>> test_grid_left = grid;
    std::vector<std::vector<double>> test_grid_right = grid;

    const CoordinateIndex start_left_pos{ 0, 2 }; // need to be set to the left side of the boundary
    DFS_fill(test_grid_left, start_left_pos, 0.0, 1.0); // after DFS fill, test_grid_left is changed
    assert(test_grid_left == solution_left_grid);

    const CoordinateIndex start_right_pos{ 1, 3 }; // need to be set to the right side of the boundary
    DFS_fill(test_grid_right, start_right_pos, 0.0, 1.0); // after DFS fill, test_grid_right is changed
    assert(test_grid_right == solution_right_grid);

    return EXIT_SUCCESS;
}