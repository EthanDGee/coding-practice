#include "beer_song.h"
#include <string>

namespace beer_song {
std::string format_beers(int count) {

    std::string beers = "";
    if (count == 0)
        beers = "no more";
    else
        beers = std::to_string(count);

    // handle bottles
    std::string plural = "s";
    if (count == 1)
        plural = "";

    beers += " bottle" + plural + " of beer";
    return beers;
}

std::string verse(int count) {

    std::string first_beer = "";
    if (count == 0)
        first_beer = "No more";
    else
        first_beer = std::to_string(count);

    std::string plural = "s";
    if (count == 1)
        plural = "";

    first_beer += " bottle" + plural + " of beer";

    // first line
    std::string first_line =
        first_beer + " on the wall, " + beer_song::format_beers(count) + ".";

    // second line

    // handle grab word
    std::string grab_word = "";
    if (count - 1 == 0)
        grab_word = "it";
    else
        grab_word = "one";

    std::string second_line;

    // format second word making sure to handle ending
    if (count != 0)
        second_line = "\nTake " + grab_word + " down and pass it around, " +
                      format_beers(count - 1) + " on the wall.\n";

    else
        second_line = "\nGo to the store and buy some more, 99 "
                      "bottles of beer on the wall.\n";

    return first_line + second_line;
}

std::string sing(int verse_start, int verse_end) {
    std::string verses = "";

    for (int verse_index = verse_start; verse_index >= verse_end;
         verse_index--) {

        verses += verse(verse_index);
        // make a gap between the in between verses
        if (verse_index != verse_end)
            verses += "\n";
    }

    return verses;
}

std::string sing(int verse_start) { return sing(verse_start, 0); }

} // namespace beer_song
