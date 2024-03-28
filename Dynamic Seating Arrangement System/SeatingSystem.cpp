#include "SeatingSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>

SeatingSystem::SeatingSystem(int numSeats) {
    seats.resize(numSeats);
}

void SeatingSystem::assignSeat(const std::string& attendeeName, int seatIndex) {
    seats[seatIndex].setAttendeeName(attendeeName);
    attendeeToSeatIndex[attendeeName] = seatIndex;
}

void SeatingSystem::printSeatingArrangement() const {
    for (int i = 0; i < seats.size(); ++i) {
        std::cout << "Seat " << i + 1 << ": ";
        if (seats[i].getAttendeeName().empty()) {
            std::cout << "Empty" << std::endl;
        }
        else {
            std::cout << seats[i].getAttendeeName() << std::endl;
        }
    }
}

void SeatingSystem::saveSeatingArrangement(const std::string& filename, const std::string& format) const {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        if (format == "txt") {
            for (int i = 0; i < seats.size(); ++i) {
                outFile << "Seat " << i + 1 << ": ";
                if (seats[i].getAttendeeName().empty()) {
                    outFile << "Empty" << std::endl;
                }
                else {
                    outFile << seats[i].getAttendeeName() << std::endl;
                }
            }
            std::cout << "Seating arrangement saved to " << filename << std::endl;
        }
        else if (format == "csv") {
            outFile << "Seat,AttendeeName" << std::endl;
            for (int i = 0; i < seats.size(); ++i) {
                outFile << i + 1 << ",";
                if (seats[i].getAttendeeName().empty()) {
                    outFile << "Empty" << std::endl;
                }
                else {
                    outFile << seats[i].getAttendeeName() << std::endl;
                }
            }
            std::cout << "Seating arrangement saved to " << filename << std::endl;
        }
        else {
            std::cerr << "Error: Unsupported format" << std::endl;
        }
        outFile.close();
    }
    else {
        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
    }
}

int SeatingSystem::getSize() const {
    return seats.size();
}

std::vector<Attendee> SeatingSystem::getUnassignedAttendees(const std::vector<Attendee>& allAttendees) const {
    std::vector<Attendee> unassignedAttendees;
    for (const auto& attendee : allAttendees) {
        if (attendeeToSeatIndex.find(attendee.getName()) == attendeeToSeatIndex.end()) {
            unassignedAttendees.push_back(attendee);
        }
    }
    return unassignedAttendees;
}

void SeatingSystem::saveSeatingArrangementCSV(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << "Seat,AttendeeName" << std::endl;
        for (int i = 0; i < seats.size(); ++i) {
            outFile << i + 1 << ",";
            if (seats[i].getAttendeeName().empty()) {
                outFile << "Empty" << std::endl;
            }
            else {
                outFile << seats[i].getAttendeeName() << std::endl;
            }
        }
        std::cout << "Seating arrangement saved to " << filename << std::endl;
        outFile.close();
    }
    else {
        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
    }
}
