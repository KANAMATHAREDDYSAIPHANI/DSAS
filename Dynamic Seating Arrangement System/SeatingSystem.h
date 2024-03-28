#ifndef SEATINGSYSTEM_H
#define SEATINGSYSTEM_H

#include "Attendee.h"
#include "Seat.h"
#include <vector>
#include <unordered_map>

class SeatingSystem {
private:
    std::vector<Seat> seats;
    std::unordered_map<std::string, int> attendeeToSeatIndex;

public:
    SeatingSystem(int numSeats);

    void assignSeat(const std::string& attendeeName, int seatIndex);
    void printSeatingArrangement() const;
    void saveSeatingArrangement(const std::string& filename, const std::string& format) const;
    int getSize() const;
    std::vector<Attendee> getUnassignedAttendees(const std::vector<Attendee>& allAttendees) const;
    void saveSeatingArrangementCSV(const std::string& filename) const;
};

#endif // SEATINGSYSTEM_H
