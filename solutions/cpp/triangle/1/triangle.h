#pragma once

namespace triangle {

// TODO: add your solution here
enum flavor {
    scalene,
    isosceles,
    equilateral,
};

template <typename T> flavor kind(T a, T b, T c);
flavor kind(int a, int b, int c);
flavor kind(double a, double b, double c);

} // namespace triangle
