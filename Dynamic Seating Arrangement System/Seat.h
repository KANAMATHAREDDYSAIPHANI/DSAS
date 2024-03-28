#ifndef SEAT_H
#define SEAT_H

#include <string>

class Seat {
private:
    std::string attendeeName;

public:
    Seat();

    std::string getAttendeeName() const;
    void setAttendeeName(const std::string& name);
};

#endif // SEAT_H
