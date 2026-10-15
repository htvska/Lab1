#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
private:
    char brand[50];
    char model[50];
    double engineVolume;
    char color[30];
    char transmissionType[30];

public:
    Car();
    Car(const char* b, const char* m, double ev, const char* c, const char* tt);
    Car(const Car& other);
    virtual ~Car();

    void setBrand(const char* b);
    void setModel(const char* m);
    void setEngineVolume(double ev);
    void setColor(const char* c);
    void setTransmissionType(const char* tt);

    const char* getBrand() const;
    const char* getModel() const;
    double getEngineVolume() const;
    const char* getColor() const;
    const char* getTransmissionType() const;

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