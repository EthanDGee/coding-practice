#include <string>

#pragma once
namespace star_map {
enum System {
    BetaHydri,
    Sol,
    EpsilonEridani,
    DeltaEridani,
    AlphaCentauri,
    Omicron2Eridani,
};
}

#pragma once
namespace heaven {
class Vessel {
  public:
    std::string name{};
    int generation = 1;
    star_map::System current_system = star_map::System::Sol;
    int busters = 0;

    Vessel replicate(std::string);
    void make_buster();
    bool shoot_buster();
};
bool in_the_same_system(Vessel vessel1, Vessel vessel2);
std::string get_older_bob(Vessel vessal1, Vessel vessel2);

} // namespace heaven
