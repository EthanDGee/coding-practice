#include <cstddef>
#include <limits>
#include <memory>
#include <string>

#pragma once
namespace troy {

struct artifact {
    // constructors needed (until C++20)
    artifact(std::string name) : name(name) {}
    std::string name;
};

struct power {
    // constructors needed (until C++20)
    power(std::string effect) : effect(effect) {}
    std::string effect;
};

class human {
  public:
    std::unique_ptr<troy::artifact> possession = nullptr;
    std::shared_ptr<troy::power> own_power = nullptr;
    std::shared_ptr<troy::power> influenced_by = nullptr;
};

void give_new_artifact(human &new_owner, std::string name);

void exchange_artifacts(std::unique_ptr<artifact> &possession1,
                        std::unique_ptr<artifact> &possession2);

void manifest_power(human &owner, std::string effect);
void use_power(human &user, human &target);
int power_intensity(human &user);

} // namespace troy
