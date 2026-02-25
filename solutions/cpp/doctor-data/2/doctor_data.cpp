#include "doctor_data.h"

namespace heaven {

Vessel Vessel::replicate(std::string name) {
    return Vessel{name, 2, star_map::System::Sol};
};

void Vessel::make_buster() { busters++; }

bool Vessel::shoot_buster() {
    if (busters >= 1) {
        busters--;
        return true;
    }
    return false;
}

std::string get_older_bob(Vessel vessel1, Vessel vessel2) {
    if (vessel1.generation < vessel2.generation)
        return vessel1.name;
    return vessel2.name;
}

bool in_the_same_system(Vessel vessel1, Vessel vessel2) {
    return vessel1.current_system == vessel2.current_system;
}
} // namespace heaven
