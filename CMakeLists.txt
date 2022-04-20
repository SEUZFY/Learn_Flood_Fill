
cmake_minimum_required (VERSION 3.8)

project ("Learn_Flood_Fill")

# find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_executable (Learn_Flood_Fill "src/Learn_Flood_Fill.hpp" "src/main.cpp" "src/matrix.hpp" "src/vector.hpp")

# target_link_libraries (Learn_Flood_Fill Eigen3::Eigen)
