#include <string>

namespace log_line {
std::string message(std::string line) {
    // return the message

    std::string message_delimeter = ":";
    // get the substring after the message start making sure to skip the space
    int message_start = line.find(message_delimeter) + 2;

    return line.substr(message_start);
}

std::string log_level(std::string line) {

    // check to find ends of  brackets then return the things between

    int tag_start = line.find("[") + 1;
    int tag_end = line.find("]");

    int log_tag_length = tag_end - tag_start;

    return line.substr(tag_start, log_tag_length);
}

std::string reformat(std::string line) {
    // return the reformatted message

    std::string tag = log_level(line);
    std::string error = message(line);

    std::string reformatted = error + " (" + tag + ")";

    return reformatted;
}
} // namespace log_line
