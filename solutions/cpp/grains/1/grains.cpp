#include "grains.h"
#include <cmath>
#include <limits>

namespace grains {

long unsigned int square(int square_num) { return exp2(square_num - 1); }

unsigned long long total() {
    // we can simply use the max as each square would flip exactly one of
    // unsigned long long's 64 bits
    return std::numeric_limits<unsigned long long>::max();
}
} // namespace grains
