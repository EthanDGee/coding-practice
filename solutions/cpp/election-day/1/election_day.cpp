#include <cstdio>
#include <string>
#include <vector>

namespace election {

// The election result struct is already created for you:

struct ElectionResult {
    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};
};

// TODO: Task 1
// vote_count takes a reference to an `ElectionResult` as an argument and will
// return the number of votes in the `ElectionResult.

int vote_count(election::ElectionResult &result) { return result.votes; }

// TODO: Task 2
// increment_vote_count takes a reference to an `ElectionResult` as an argument
// and a number of votes (int), and will increment the `ElectionResult` by that
// number of votes.

void increment_vote_count(election::ElectionResult &result, int vote_count) {
    result.votes += vote_count;
}

// TODO: Task 3
// determine_result receives the reference to a final_count and returns a
// reference to the `ElectionResult` of the new president. It also changes the
// name of the winner by prefixing it with "President". The final count is given
// in the form of a `reference` to `std::vector<ElectionResult>`, a vector with
// `ElectionResults` of all the participating candidates.

election::ElectionResult &
determine_result(std::vector<election::ElectionResult> &results) {
    election::ElectionResult *winner = &results[0];

    for (int i = 1; i < results.size(); i++) {
        if (results[i].votes > winner->votes)
            winner = &results[i];
    }

    // modify winner to have president in their name

    winner->name = "President " + winner->name;

    return *winner;
}

} // namespace election
