#include "Seat.h"

Seat::Seat() : attendeeName("") {}

std::string Seat::getAttendeeName() const {
    return attendeeName;
}

void Seat::setAttendeeName(const std::string& name) {
    attendeeName = name;
}
