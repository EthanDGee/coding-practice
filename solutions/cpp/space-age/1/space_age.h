#pragma once

namespace space_age {
class space_age {
  public:
    long int age_in_seconds;

    space_age(long int seconds) { age_in_seconds = seconds; }

    int seconds() const;
    double on_mercury() const;
    double on_venus() const;
    double on_earth() const;
    double on_mars() const;
    double on_jupiter() const;
    double on_saturn() const;
    double on_uranus() const;
    double on_neptune() const;
};

const space_age age(long int seconds);
} // namespace space_age
