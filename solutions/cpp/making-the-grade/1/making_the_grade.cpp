#include <array>
#include <cstdlib>
#include <string>
#include <vector>

#define PASS_THRESHOLD 40

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {

    std::vector<int> rounded_scores;
    for (auto score : student_scores) {
        rounded_scores.emplace_back(int(score));
    }
    return rounded_scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int total_failing = 0;

    for (auto score : student_scores) {
        if (score <= PASS_THRESHOLD)
            total_failing++;
    }
    return total_failing;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    // TODO: Implement letter_grades

    int range = highest_score - PASS_THRESHOLD;
    int split = range / 4;

    std::array<int, 4> grades;

    for (int i = 0; i <= grades.size(); i++) {
        grades[i] = PASS_THRESHOLD + 1 + (split * i);
    }

    return grades;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string>
student_ranking(std::vector<int> student_scores,
                std::vector<std::string> student_names) {
    // TODO: Implement student_ranking

    std::vector<std::string> ranking;

    // loop through the vector find the max add to ranking remove from score
    // vectors;
    while (!student_scores.empty()) {
        int max_score = -1;
        int max_index = 0;

        // find max score
        for (int i = 0; i < student_scores.size(); i++) {
            if (student_scores[i] > max_score) {
                max_index = i;
                max_score = student_scores[i];
            }
        }

        // remove top scorer and add to ranking
        std::string formatted_ranking =
            std::to_string(ranking.size() + 1) + ". " +
            student_names[max_index] + ": " +
            std::to_string(student_scores[max_index]);

        ranking.emplace_back(formatted_ranking);

        student_scores.erase(student_scores.begin() + max_index);
        student_names.erase(student_names.begin() + max_index);
    }
    return ranking;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    // TODO: Implement perfect_score

    for (int i = 0; i < student_scores.size(); i++) {
        if (student_scores[i] == 100)
            return student_names[i];
    }

    return "";
}
