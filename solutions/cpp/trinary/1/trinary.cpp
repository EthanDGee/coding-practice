#include "trinary.h"
#include <cmath>
#include <string>

namespace trinary {

int to_decimal(std::string trinary_number) {

    int decimal = 0;

    // go digit by digit and it times 3 ^ power of place to decimal
    for (long unsigned int i = 0; i < trinary_number.length(); i++) {

        int digit = trinary_number[i] - '0';
        if (digit < 0 || digit > 2)
            return 0;
        // as we loop check for invalid characters and exit early if found

        int place = trinary_number.length() - (i + 1);
        int power = std::pow(3, place);
        decimal += digit * power;
    }

    return decimal;
}

} // namespace trinary
