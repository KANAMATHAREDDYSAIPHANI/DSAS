#ifndef ATTENDEE_H
#define ATTENDEE_H

#include <string>

class Attendee {
private:
    std::string name;
    std::string preference;

public:
    Attendee(const std::string& n, const std::string& p);

    std::string getName() const;
    std::string getPreference() const;
};

#endif // ATTENDEE_H
