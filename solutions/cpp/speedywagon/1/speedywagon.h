#include <string>
#include <vector>

#pragma once
namespace speedywagon {

struct pillar_men_sensor {
    int activity{};
    std::string location{};
    std::vector<int> data{};
};

int uv_light_heuristic(std::vector<int> *data_array);
int activity_counter(pillar_men_sensor *array, int breakpoint);
bool alarm_control(pillar_men_sensor *sensor);
bool uv_alarm(pillar_men_sensor *sensor);

bool connection_check(pillar_men_sensor *sensor);
} // namespace speedywagon
