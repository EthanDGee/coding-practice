#include "sieve.h"
#include <vector>

namespace sieve {

void mark_factors(int n, std::vector<bool> &nums) {

    // loop multiples of n marking multiples
    long unsigned int multiple = 2;
    while (multiple * n <= nums.size() + 2) {
        nums[multiple * n - 2] = false;
        multiple++;
    }
}

std::vector<int> primes(int n) {

    std::vector<int> prime_numbers;
    if (n < 2)
        return prime_numbers;

    // create boolean vector of size n - 1 (2 to n)
    std::vector<bool> is_prime;
    for (int i = 2; i <= n; i++) {
        is_prime.emplace_back(true);
    }

    int current_num = 2;
    do {
        if (is_prime[current_num - 2]) {
            sieve::mark_factors(current_num, is_prime);
            prime_numbers.emplace_back(current_num);
        }
        current_num++;
    }
    // loop from 2 to n
    while (current_num <= n);

    // if a new prime mark it as prime then all of its multiples as not
    // primes
    return prime_numbers;
}

} // namespace sieve
