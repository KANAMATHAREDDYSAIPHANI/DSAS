#include "SeatingSystem.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // For rand()

int main() {
    // Get the number of seats from the user
    int numSeats;
    std::cout << "Enter the number of seats: ";
    std::cin >> numSeats;

    // Initialize the seating system with the provided number of seats
    SeatingSystem seatingSystem(numSeats);

    // Get attendee details from the user
    std::vector<Attendee> attendees;
    std::string name, preference;
    char addMore;
    do {
        std::cout << "Enter attendee name: ";
        std::cin >> name;
        std::cout << "Enter attendee preference (Window/Aisle/Center): ";
        std::cin >> preference;
        attendees.push_back({ name, preference });

        std::cout << "Do you want to add another attendee? (y/n): ";
        std::cin >> addMore;
    } while (addMore == 'y' || addMore == 'Y');

    // Assign seats based on attendee preferences
    for (const auto& attendee : attendees) {
        // For simplicity, randomly assign seats here
        int seatIndex = std::rand() % seatingSystem.getSize();
        seatingSystem.assignSeat(attendee.getName(), seatIndex);
    }

    // Print the seating arrangement
    std::cout << "Initial Seating Arrangement:" << std::endl;
    seatingSystem.printSeatingArrangement();

    // Save the seating arrangement to a text file
    std::string filename;
    std::cout << "Enter filename to save the seating arrangement: ";
    std::cin >> filename;
    seatingSystem.saveSeatingArrangement(filename, "txt");

    // Get unassigned attendees
    std::vector<Attendee> unassignedAttendees = seatingSystem.getUnassignedAttendees(attendees);
    if (!unassignedAttendees.empty()) {
        std::cout << "Unassigned Attendees:" << std::endl;
        for (const auto& attendee : unassignedAttendees) {
            std::cout << attendee.getName() << std::endl;
        }
    }
    else {
        std::cout << "All attendees are assigned seats." << std::endl;
    }

    return 0;
}
