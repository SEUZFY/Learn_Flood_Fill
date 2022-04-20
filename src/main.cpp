
#include "vector.hpp"

void process_2d_vector(float* dptr) {

}

int main() {
    Vector<2, float> vec2d;
    process_2d_vector(vec2d);

    std::cout << "size: " << vec2d.size() << '\n';
    std::cout << "default constructor: ";
    vec2d.print();

    Vector<2, float> vec_a;
    Vector<2, float> vec_b;

    // set vec_a and vec_b
    auto a_data = vec_a.Getdata();
    a_data[0] = 1;
    a_data[1] = 1;
    std::cout << "vector a: ";
    vec_a.print();

    auto b_data = vec_b.Getdata();
    b_data[0] = 2;
    b_data[1] = 2;
    std::cout << "vector b: ";
    vec_b.print();

    auto sum_vec = vec_a + vec_b;
    std::cout << "sum vector: ";
    sum_vec.print();

    auto multiply_vec = vec_a / 1;
    std::cout << "multiply vector: ";
    multiply_vec.print();

    return EXIT_SUCCESS;
}