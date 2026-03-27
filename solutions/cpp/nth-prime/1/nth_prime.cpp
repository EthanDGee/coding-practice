#include "nth_prime.h"
#include "test/catch.hpp"
#include <cstdio>
#include <vector>

namespace nth_prime {

// TODO: add your solution here
int nth(long unsigned int n) {
    if (n == 0)
        Catch::throw_domain_error("This function uses 1 indexing");

    std::vector<int> primes;
    primes.push_back(2);

    int i = 3;
    while (primes.size() <= n - 1) {

        bool has_factor = false;

        long unsigned int prime_id = 0;
        while (prime_id < primes.size() && !has_factor) {
            has_factor = i % primes[prime_id] == 0;
            prime_id++;
        }
        if (!has_factor)
            primes.push_back(i);

        i++;
    }

    return primes.back();
}

} // namespace nth_prime
