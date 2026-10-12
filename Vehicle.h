#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <fstream>

class Vehicle {
public:
    Vehicle();
    Vehicle(const Vehicle&);
    virtual ~Vehicle();

    virtual void print(std::ostream& out) const = 0;
    virtual void save(std::ostream& out) const = 0;
    virtual void load(std::istream& in) = 0;
    virtual void input() = 0;
    virtual void edit() = 0;
    virtual const char* getType() const = 0;
    virtual int getTypeCode() const = 0;
    virtual Vehicle* clone() const = 0;
};

std::ostream& operator<<(std::ostream& out, const Vehicle& v);

#endif
