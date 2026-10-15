#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

class Motorcycle : public Vehicle {
private:
    char brand[50];
    char model[50];
    double engineVolume;
    double power;
    char terrain[50];

public:
    Motorcycle();
    Motorcycle(const char* b, const char* m, double ev, double p, const char* t);
    Motorcycle(const Motorcycle& other);
    virtual ~Motorcycle();

    void setBrand(const char* b);
    void setModel(const char* m);
    void setEngineVolume(double ev);
    void setPower(double p);
    void setTerrain(const char* t);

    const char* getBrand() const;
    const char* getModel() const;
    double getEngineVolume() const;
    double getPower() const;
    const char* getTerrain() const;

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