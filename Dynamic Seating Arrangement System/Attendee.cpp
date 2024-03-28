#include "Attendee.h"

Attendee::Attendee(const std::string& n, const std::string& p) : name(n), preference(p) {}

std::string Attendee::getName() const {
    return name;
}

std::string Attendee::getPreference() const {
    return preference;
}
