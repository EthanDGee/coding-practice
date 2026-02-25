#include "doctor_data.h"

heaven::Vessel heaven::Vessel::replicate(std::string name) {
    return heaven::Vessel{name, 2, star_map::System::Sol};
};

void heaven::Vessel::make_buster() { busters++; }

bool heaven::Vessel::shoot_buster() {
    if (busters >= 1) {
        busters--;
        return true;
    }
    return false;
}

std::string heaven::get_older_bob(heaven::Vessel vessel1,
                                  heaven::Vessel vessel2) {
    if (vessel1.generation < vessel2.generation)
        return vessel1.name;
    return vessel2.name;
}

bool heaven::in_the_same_system(Vessel vessel1, Vessel vessel2) {
    return vessel1.current_system == vessel2.current_system;
}
