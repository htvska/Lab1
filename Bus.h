#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"

class Bus : public Vehicle {
private:
    char brand[50];
    char model[50];
    int seatedPlaces;
    int totalPlaces;
    char destination[50];

public:
    Bus();
    Bus(const char* b, const char* m, int sp, int tp, const char* d);
    Bus(const Bus& other);
    virtual ~Bus();

    void setBrand(const char* b);
    void setModel(const char* m);
    void setSeatedPlaces(int sp);
    void setTotalPlaces(int tp);
    void setDestination(const char* d);

    const char* getBrand() const;
    const char* getModel() const;
    int getSeatedPlaces() const;
    int getTotalPlaces() const;
    const char* getDestination() const;

    virtual void print(std::ostream& out) const;
    virtual void save(std::ostream& out) const;
    virtual void load(std::istream& in);
    virtual void input();
    virtual void edit();
    virtual const char* getType() const;
    virtual int getTypeCode() const;
    virtual Vehicle* clone() const;
};

#endif