#include "power_of_troy.h"
#include <memory>
#include <utility>

namespace troy {
void give_new_artifact(human &new_owner, std::string name) {
    new_owner.possession = std::make_unique<troy::artifact>(name);
}

void exchange_artifacts(std::unique_ptr<artifact> &possession1,
                        std::unique_ptr<artifact> &possession2) {
    std::unique_ptr<artifact> swap = std::move(possession1);
    possession1 = std::move(possession2);
    possession2 = std::move(swap);
}

void manifest_power(human &owner, std::string effect) {
    power new_power{effect};
    owner.own_power = std::make_shared<power>(effect);
}

void use_power(human &user, human &target) {
    target.influenced_by = user.own_power;
}

int power_intensity(human &user) { return user.own_power.use_count(); }

} // namespace troy
