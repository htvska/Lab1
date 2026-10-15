#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"
#include <cstring>
#include <stdexcept>
#include <limits>
#include <iostream>

Car::Car() : Vehicle(), engineVolume(0) {
    brand[0] = '\0';
    model[0] = '\0';
    color[0] = '\0';
    transmissionType[0] = '\0';
    std::cout << "Car default constructor called\n";
}

Car::Car(const char* b, const char* m, double ev, const char* c, const char* tt)
    : Vehicle(), engineVolume(ev) {
    if (ev <= 0) throw std::invalid_argument("Engine volume must be positive");
    std::strncpy(brand, b, 49); brand[49] = '\0';
    std::strncpy(model, m, 49); model[49] = '\0';
    std::strncpy(color, c, 29); color[29] = '\0';
    std::strncpy(transmissionType, tt, 29); transmissionType[29] = '\0';
    std::cout << "Car parameterized constructor called\n";
}

Car::Car(const Car& other) : Vehicle(other), engineVolume(other.engineVolume) {
    std::strncpy(brand, other.brand, 50);
    std::strncpy(model, other.model, 50);
    std::strncpy(color, other.color, 30);
    std::strncpy(transmissionType, other.transmissionType, 30);
    std::cout << "Car copy constructor called\n";
}

Car::~Car() {
    std::cout << "Car destructor called\n";
}

void Car::setBrand(const char* b) {
    if (b == nullptr || std::strlen(b) == 0)
        throw std::invalid_argument("Brand cannot be empty");
    std::strncpy(brand, b, 49); brand[49] = '\0';
}

void Car::setModel(const char* m) {
    if (m == nullptr || std::strlen(m) == 0)
        throw std::invalid_argument("Model cannot be empty");
    std::strncpy(model, m, 49); model[49] = '\0';
}

void Car::setEngineVolume(double ev) {
    if (ev <= 0) throw std::invalid_argument("Engine volume must be positive");
    engineVolume = ev;
}

void Car::setColor(const char* c) {
    if (c == nullptr || std::strlen(c) == 0)
        throw std::invalid_argument("Color cannot be empty");
    std::strncpy(color, c, 29); color[29] = '\0';
}

void Car::setTransmissionType(const char* tt) {
    if (tt == nullptr || std::strlen(tt) == 0)
        throw std::invalid_argument("Transmission type cannot be empty");
    std::strncpy(transmissionType, tt, 29); transmissionType[29] = '\0';
}

const char* Car::getBrand() const { return brand; }
const char* Car::getModel() const { return model; }
double Car::getEngineVolume() const { return engineVolume; }
const char* Car::getColor() const { return color; }
const char* Car::getTransmissionType() const { return transmissionType; }

void Car::print(std::ostream& out) const {
    out << "Car: brand=" << brand
        << ", model=" << model
        << ", engineVolume=" << engineVolume
        << ", color=" << color
        << ", transmission=" << transmissionType;
}

void Car::save(std::ostream& out) const {
    out.write(brand, sizeof(brand));
    out.write(model, sizeof(model));
    out.write(reinterpret_cast<const char*>(&engineVolume), sizeof(engineVolume));
    out.write(color, sizeof(color));
    out.write(transmissionType, sizeof(transmissionType));
}

void Car::load(std::istream& in) {
    in.read(brand, sizeof(brand));
    in.read(model, sizeof(model));
    in.read(reinterpret_cast<char*>(&engineVolume), sizeof(engineVolume));
    in.read(color, sizeof(color));
    in.read(transmissionType, sizeof(transmissionType));
}

void Car::input() {
    std::cout << "Enter brand: ";
    std::cin.getline(brand, 50);
    if (std::strlen(brand) == 0) throw std::invalid_argument("Brand cannot be empty");

    std::cout << "Enter model: ";
    std::cin.getline(model, 50);
    if (std::strlen(model) == 0) throw std::invalid_argument("Model cannot be empty");

    std::cout << "Enter engine volume: ";
    std::cin >> engineVolume;
    if (engineVolume <= 0) throw std::invalid_argument("Engine volume must be positive");
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter color: ";
    std::cin.getline(color, 30);
    if (std::strlen(color) == 0) throw std::invalid_argument("Color cannot be empty");

    std::cout << "Enter transmission type: ";
    std::cin.getline(transmissionType, 30);
    if (std::strlen(transmissionType) == 0) throw std::invalid_argument("Transmission type cannot be empty");
}

void Car::edit() {
    std::cout << "Editing Car. Current data:\n";
    print(std::cout);
    std::cout << "\n";
    input();
}

const char* Car::getType() const { return "Car"; }
int Car::getTypeCode() const { return 1; }
Vehicle* Car::clone() const { return new Car(*this); }