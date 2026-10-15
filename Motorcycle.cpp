#define _CRT_SECURE_NO_WARNINGS
#include "Motorcycle.h"
#include <cstring>
#include <stdexcept>
#include <limits>
#include <iostream>

Motorcycle::Motorcycle() : Vehicle(), engineVolume(0), power(0) {
    brand[0] = '\0';
    model[0] = '\0';
    terrain[0] = '\0';
    std::cout << "Motorcycle default constructor called\n";
}

Motorcycle::Motorcycle(const char* b, const char* m, double ev, double p, const char* t)
    : Vehicle(), engineVolume(ev), power(p) {
    if (ev <= 0) throw std::invalid_argument("Engine volume must be positive");
    if (p <= 0) throw std::invalid_argument("Power must be positive");
    std::strncpy(brand, b, 49); brand[49] = '\0';
    std::strncpy(model, m, 49); model[49] = '\0';
    std::strncpy(terrain, t, 49); terrain[49] = '\0';
    std::cout << "Motorcycle parameterized constructor called\n";
}

Motorcycle::Motorcycle(const Motorcycle& other)
    : Vehicle(other), engineVolume(other.engineVolume), power(other.power) {
    std::strncpy(brand, other.brand, 50);
    std::strncpy(model, other.model, 50);
    std::strncpy(terrain, other.terrain, 50);
    std::cout << "Motorcycle copy constructor called\n";
}

Motorcycle::~Motorcycle() {
    std::cout << "Motorcycle destructor called\n";
}

void Motorcycle::setBrand(const char* b) {
    if (b == nullptr || std::strlen(b) == 0)
        throw std::invalid_argument("Brand cannot be empty");
    std::strncpy(brand, b, 49); brand[49] = '\0';
}

void Motorcycle::setModel(const char* m) {
    if (m == nullptr || std::strlen(m) == 0)
        throw std::invalid_argument("Model cannot be empty");
    std::strncpy(model, m, 49); model[49] = '\0';
}

void Motorcycle::setEngineVolume(double ev) {
    if (ev <= 0) throw std::invalid_argument("Engine volume must be positive");
    engineVolume = ev;
}

void Motorcycle::setPower(double p) {
    if (p <= 0) throw std::invalid_argument("Power must be positive");
    power = p;
}

void Motorcycle::setTerrain(const char* t) {
    if (t == nullptr || std::strlen(t) == 0)
        throw std::invalid_argument("Terrain cannot be empty");
    std::strncpy(terrain, t, 49); terrain[49] = '\0';
}

const char* Motorcycle::getBrand() const { return brand; }
const char* Motorcycle::getModel() const { return model; }
double Motorcycle::getEngineVolume() const { return engineVolume; }
double Motorcycle::getPower() const { return power; }
const char* Motorcycle::getTerrain() const { return terrain; }

void Motorcycle::print(std::ostream& out) const {
    out << "Motorcycle: brand=" << brand
        << ", model=" << model
        << ", engineVolume=" << engineVolume
        << ", power=" << power
        << ", terrain=" << terrain;
}

void Motorcycle::save(std::ostream& out) const {
    out.write(brand, sizeof(brand));
    out.write(model, sizeof(model));
    out.write(reinterpret_cast<const char*>(&engineVolume), sizeof(engineVolume));
    out.write(reinterpret_cast<const char*>(&power), sizeof(power));
    out.write(terrain, sizeof(terrain));
}

void Motorcycle::load(std::istream& in) {
    in.read(brand, sizeof(brand));
    in.read(model, sizeof(model));
    in.read(reinterpret_cast<char*>(&engineVolume), sizeof(engineVolume));
    in.read(reinterpret_cast<char*>(&power), sizeof(power));
    in.read(terrain, sizeof(terrain));
}

void Motorcycle::input() {
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

    std::cout << "Enter power: ";
    std::cin >> power;
    if (power <= 0) throw std::invalid_argument("Power must be positive");
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter terrain: ";
    std::cin.getline(terrain, 50);
    if (std::strlen(terrain) == 0) throw std::invalid_argument("Terrain cannot be empty");
}

void Motorcycle::edit() {
    std::cout << "Editing Motorcycle. Current data:\n";
    print(std::cout);
    std::cout << "\n";
    input();
}

const char* Motorcycle::getType() const { return "Motorcycle"; }
int Motorcycle::getTypeCode() const { return 2; }
Vehicle* Motorcycle::clone() const { return new Motorcycle(*this); }