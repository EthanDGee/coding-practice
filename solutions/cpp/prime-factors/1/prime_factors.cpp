#include "prime_factors.h"

namespace prime_factors {

// TODO: add your solution here
std::vector<long long> of(long long num) {
    std::vector<long long> factors;

    // handle base primes.
    if (num == 1) {
        return factors;
    }
    if (num <= 3) {
        factors.emplace_back(num);
        return factors;
    }

    int divisor = 2;
    while (divisor < num) {
        // if the divisor can be divided repeatedly divide
        while (num % divisor == 0) {
            num /= divisor;
            factors.emplace_back(divisor);
        }
        // move to the next number, this will increment conitunally and will
        // pass over non-primes
        divisor++;
    }

    // if the number wasn't already added add it
    if (num >= 2 && num != factors.back()) {
        factors.emplace_back(num);
    }

    return factors;
}

} // namespace prime_factors
