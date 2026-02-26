#include "hamming.h"
#include <stdexcept>

namespace hamming {

int compute(std::string string1, std::string string2) {

    // throw an exception when strings are not same size as hamming distance
    // cannot be computed.

    if (string1.length() != string2.length())
        throw std::domain_error("Hamming distance cannot be computed for "
                                "sequences of inequal length.");

    int distance = 0;
    for (long unsigned int i = 0; i < string1.length(); i++) {
        // since booleans are 0 or 1 we can simply add the result
        distance += string1[i] != string2[i];
    }

    return distance;
}

} // namespace hamming
