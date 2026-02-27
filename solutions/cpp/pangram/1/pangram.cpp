#include "pangram.h"
#include <iostream>
namespace pangram {

bool is_pangram(std::string sentence) {
    // if the sentence is less than the length of the alphabet we know for sure
    // that not all letters are seen
    std::cout << sentence;
    printf("\n\n");
    if (sentence.length() < 26)
        return false;

    // boolean array to store if all letters have been seen
    bool letters[26];

    // initialize to false;
    for (auto &letter : letters) {
        letter = false;
    }

    // total letters seen to allow for early exit without looping through
    // letters
    int total_letters_seen = 0;

    const int UPPER_CASE_START = 'A';
    const int UPPER_CASE_END = 'Z';
    const int LOWER_CASE_START = 'a';
    const int LOWER_CASE_END = 'z';

    long unsigned int index = 0;
    // loop through sentence until all letters have been found or string
    // terminates
    while (total_letters_seen < 26 && index <= sentence.length()) {
        // check to see if it's in letter range then update index of letter
        unsigned int unicode = sentence[index];
        unsigned int letter = 0;
        // split based on lower case and  upper case
        if (UPPER_CASE_START <= unicode && unicode <= UPPER_CASE_END) {
            letter = unicode - UPPER_CASE_START;
        } else if (LOWER_CASE_START <= unicode && unicode <= LOWER_CASE_END) {
            letter = unicode - LOWER_CASE_START;
        } else {
            index++;
            continue;
        }

        // update count
        if (!letters[letter]) {
            letters[letter] = true;
            total_letters_seen++;
        }
        index++;
    }
    printf("%d\n", total_letters_seen);

    return total_letters_seen == 26;
}

} // namespace pangram
