#define _CRT_SECURE_NO_WARNINGS
#include "Vehicle.h"

Vehicle::Vehicle() {
    std::cout << "Vehicle constructor called\n";
}

Vehicle::Vehicle(const Vehicle&) {
    std::cout << "Vehicle copy constructor called\n";
}

Vehicle::~Vehicle() {
    std::cout << "Vehicle destructor called\n";
}

std::ostream& operator<<(std::ostream& out, const Vehicle& v) {
    v.print(out);
    return out;
}