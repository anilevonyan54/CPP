#include <iostream>
using namespace std;

// Abstract Product Interface for Car
class Car {
public:
    virtual void assemble() = 0; // Pure virtual function
    virtual ~Car() {}
};

// Abstract Product Interface for Car Specifications
class CarSpecification {
public:
    virtual void display() = 0; // Pure virtual function
    virtual ~CarSpecification() {}
};

// Concrete Product for Sedan Car
class Sedan : public Car {
public:
    void assemble() override {
        cout << "Assembling Sedan car." << endl;
    }
};

// Concrete Product for Hatchback Car
class Hatchback : public Car {
public:
    void assemble() override {
        cout << "Assembling Hatchback car." << endl;
    }
};

// Concrete Product for North America Car Specification
class NorthAmericaSpecification : public CarSpecification {
public:
    void display() override {
        cout << "North America Car Specification: Safety features compliant with local regulations." << endl;
    }
};

// Concrete Product for Europe Car Specification
class EuropeSpecification : public CarSpecification {
public:
    void display() override {
        cout << "Europe Car Specification: Fuel efficiency and emissions compliant with EU standards." << endl;
    }
};

// Abstract Factory Interface
class CarFactory {
public:
    virtual Car* createCar() = 0; // Factory method for Car
    virtual CarSpecification* createSpecification() = 0; // Factory method for Car Specification
    virtual ~CarFactory() {}
};

// Concrete Factory for North America Cars
class NorthAmericaCarFactory : public CarFactory {
public:
    Car* createCar() override {
        return new Sedan(); // Creates a Sedan for North America
    }

    CarSpecification* createSpecification() override {
        return new NorthAmericaSpecification(); // Creates specification for North America
    }
};

// Concrete Factory for Europe Cars
class EuropeCarFactory : public CarFactory {
public:
    Car* createCar() override {
        return new Hatchback(); // Creates a Hatchback for Europe
    }

    CarSpecification* createSpecification() override {
        return new EuropeSpecification(); // Creates specification for Europe
    }
};

// Client Code
int main() {
    // Creating cars for North America
    CarFactory* northAmericaFactory = new NorthAmericaCarFactory();
    Car* northAmericaCar = northAmericaFactory->createCar();
    CarSpecification* northAmericaSpec = northAmericaFactory->createSpecification();

    northAmericaCar->assemble();
    northAmericaSpec->display();

    // Creating cars for Europe
    CarFactory* europeFactory = new EuropeCarFactory();
    Car* europeCar = europeFactory->createCar();
    CarSpecification* europeSpec = europeFactory->createSpecification();

    europeCar->assemble();
    europeSpec->display();

    // Clean up dynamically allocated memory
    delete northAmericaFactory;
    delete europeFactory;
    delete northAmericaCar;
    delete northAmericaSpec;
    delete europeCar;
    delete europeSpec;

    return 0;
}
