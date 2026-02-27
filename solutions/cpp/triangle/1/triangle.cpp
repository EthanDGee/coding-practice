#include "triangle.h"
#include <stdexcept>

namespace triangle {

template <typename T> triangle::flavor kind(T a, T b, T c) {

    // check to see if sides are valid
    if (a <= 0 || b <= 0 || c <= 0)
        throw std::domain_error("All sides must have lengths greater than 0.");

    // check to see if lengths can form valid triangle
    if (a + b < c)
        throw std::domain_error(
            "Sides a + b must be greater than or equal than c");
    else if (a + c < b)
        throw std::domain_error(
            "Sides a + c must be greater thanor equal to b");
    if (b + c < a)
        throw std::domain_error(
            "Sides b + c must be greater than or equal than a");

    int matching_sides = 0;

    if (a == b) {
        matching_sides++;
    }
    if (a == c) {
        matching_sides++;
    }
    if (b == c) {
        matching_sides++;
    }

    switch (matching_sides) {
    case 1:
        return flavor::isosceles;
    case 2:
        return flavor::scalene;
    case 3:
        return flavor::equilateral;
    default:
        return flavor::scalene;
    }
}

flavor kind(int a, int b, int c) { return kind<int>(a, b, c); };
flavor kind(double a, double b, double c) { return kind<double>(a, b, c); };

} // namespace triangle
