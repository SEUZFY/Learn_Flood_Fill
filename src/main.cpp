
#include "vector.hpp"

void process_2d_vector(float* dptr) {

}

int main() {
    Vector<2, float> vec2d;
    process_2d_vector(vec2d);

    std::cout << "size: " << vec2d.size() << '\n';
    vec2d.print();

    return EXIT_SUCCESS;
}