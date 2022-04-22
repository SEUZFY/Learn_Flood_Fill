
//#include "vector.hpp"
//#include "demo_lvalue_rvalue.hpp"
#include "Learn_Flood_Fill.hpp"

void process_2d_vector(float* dptr) {

}

int main() {
    //Vector<2, float> vec2d;
    //process_2d_vector(vec2d);

    //std::cout << "size: " << vec2d.size() << '\n';
    //std::cout << "default constructor: ";
    //vec2d.print();

    //Vector<2, float> vec_a;
    //Vector<2, float> vec_b;

    //// set vec_a and vec_b
    //auto a_data = vec_a.Getdata();
    //a_data[0] = 1;
    //a_data[1] = 1;
    //std::cout << "vector a: ";
    //vec_a.print();

    //auto b_data = vec_b.Getdata();
    //b_data[0] = 2;
    //b_data[1] = 2;
    //std::cout << "vector b: ";
    //vec_b.print();

    //auto sum_vec = vec_a + vec_b;
    //std::cout << "sum vector: ";
    //sum_vec.print();

    //auto multiply_vec = vec_a / 1;
    //std::cout << "multiply vector: ";
    //multiply_vec.print();

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

    const CoordinateIndex start_left_pos(0, 2); // need to be set to the left side of the boundary
    DFS_fill(test_grid_left, start_left_pos, 0.0, 1.0); // after DFS fill, test_grid_left is changed
    assert(test_grid_left == solution_left_grid);

    const CoordinateIndex start_right_pos(1, 3); // need to be set to the right side of the boundary
    DFS_fill(test_grid_right, start_right_pos, 0.0, 1.0); // after DFS fill, test_grid_right is changed
    assert(test_grid_right == solution_right_grid);

    return EXIT_SUCCESS;
}