#define _CRT_SECURE_NO_WARNINGS
#include "Bus.h"
#include <cstring>
#include <stdexcept>
#include <limits>
#include <iostream>

Bus::Bus() : Vehicle(), seatedPlaces(0), totalPlaces(0) {
    brand[0] = '\0';
    model[0] = '\0';
    destination[0] = '\0';
    std::cout << "Bus default constructor called\n";
}

Bus::Bus(const char* b, const char* m, int sp, int tp, const char* d)
    : Vehicle(), seatedPlaces(sp), totalPlaces(tp) {
    if (sp <= 0) throw std::invalid_argument("Seated places must be positive");
    if (tp < sp) throw std::invalid_argument("Total places cannot be less than seated places");
    std::strncpy(brand, b, 49); brand[49] = '\0';
    std::strncpy(model, m, 49); model[49] = '\0';
    std::strncpy(destination, d, 49); destination[49] = '\0';
    std::cout << "Bus parameterized constructor called\n";
}

Bus::Bus(const Bus& other)
    : Vehicle(other), seatedPlaces(other.seatedPlaces), totalPlaces(other.totalPlaces) {
    std::strncpy(brand, other.brand, 50);
    std::strncpy(model, other.model, 50);
    std::strncpy(destination, other.destination, 50);
    std::cout << "Bus copy constructor called\n";
}

Bus::~Bus() {
    std::cout << "Bus destructor called\n";
}

void Bus::setBrand(const char* b) {
    if (b == nullptr || std::strlen(b) == 0)
        throw std::invalid_argument("Brand cannot be empty");
    std::strncpy(brand, b, 49); brand[49] = '\0';
}

void Bus::setModel(const char* m) {
    if (m == nullptr || std::strlen(m) == 0)
        throw std::invalid_argument("Model cannot be empty");
    std::strncpy(model, m, 49); model[49] = '\0';
}

void Bus::setSeatedPlaces(int sp) {
    if (sp <= 0) throw std::invalid_argument("Seated places must be positive");
    if (sp > totalPlaces) throw std::invalid_argument("Seated places cannot exceed total places");
    seatedPlaces = sp;
}

void Bus::setTotalPlaces(int tp) {
    if (tp < seatedPlaces) throw std::invalid_argument("Total places cannot be less than seated places");
    totalPlaces = tp;
}

void Bus::setDestination(const char* d) {
    if (d == nullptr || std::strlen(d) == 0)
        throw std::invalid_argument("Destination cannot be empty");
    std::strncpy(destination, d, 49); destination[49] = '\0';
}

const char* Bus::getBrand() const { return brand; }
const char* Bus::getModel() const { return model; }
int Bus::getSeatedPlaces() const { return seatedPlaces; }
int Bus::getTotalPlaces() const { return totalPlaces; }
const char* Bus::getDestination() const { return destination; }

void Bus::print(std::ostream& out) const {
    out << "Bus: brand=" << brand
        << ", model=" << model
        << ", seatedPlaces=" << seatedPlaces
        << ", totalPlaces=" << totalPlaces
        << ", destination=" << destination;
}

void Bus::save(std::ostream& out) const {
    out.write(brand, sizeof(brand));
    out.write(model, sizeof(model));
    out.write(reinterpret_cast<const char*>(&seatedPlaces), sizeof(seatedPlaces));
    out.write(reinterpret_cast<const char*>(&totalPlaces), sizeof(totalPlaces));
    out.write(destination, sizeof(destination));
}

void Bus::load(std::istream& in) {
    in.read(brand, sizeof(brand));
    in.read(model, sizeof(model));
    in.read(reinterpret_cast<char*>(&seatedPlaces), sizeof(seatedPlaces));
    in.read(reinterpret_cast<char*>(&totalPlaces), sizeof(totalPlaces));
    in.read(destination, sizeof(destination));
}

void Bus::input() {
    std::cout << "Enter brand: ";
    std::cin.getline(brand, 50);
    if (std::strlen(brand) == 0) throw std::invalid_argument("Brand cannot be empty");

    std::cout << "Enter model: ";
    std::cin.getline(model, 50);
    if (std::strlen(model) == 0) throw std::invalid_argument("Model cannot be empty");

    std::cout << "Enter seated places: ";
    std::cin >> seatedPlaces;
    if (seatedPlaces <= 0) throw std::invalid_argument("Seated places must be positive");
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter total places: ";
    std::cin >> totalPlaces;
    if (totalPlaces < seatedPlaces) throw std::invalid_argument("Total places cannot be less than seated places");
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter destination: ";
    std::cin.getline(destination, 50);
    if (std::strlen(destination) == 0) throw std::invalid_argument("Destination cannot be empty");
}

void Bus::edit() {
    std::cout << "Editing Bus. Current data:\n";
    print(std::cout);
    std::cout << "\n";
    input();
}

const char* Bus::getType() const { return "Bus"; }
int Bus::getTypeCode() const { return 3; }
Vehicle* Bus::clone() const { return new Bus(*this); }