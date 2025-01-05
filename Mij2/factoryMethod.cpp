#include <iostream>
using namespace std;

// Abstract class for Vehicle
class Vehicle {
public:
    virtual void printVehicle() = 0; // Pure virtual function
    virtual ~Vehicle() {} // Virtual destructor
};

// Concrete class for TwoWheeler
class TwoWheeler : public Vehicle {
public:
    void printVehicle() override {
        cout << "I am two wheeler" << endl;
    }
};

// Concrete class for FourWheeler
class FourWheeler : public Vehicle {
public:
    void printVehicle() override {
        cout << "I am four wheeler" << endl;
    }
};

// Abstract Factory Interface
class VehicleFactory {
public:
    virtual Vehicle* createVehicle() = 0; // Pure virtual factory method
    virtual ~VehicleFactory() {} // Virtual destructor
};

// Concrete Factory for TwoWheeler
class TwoWheelerFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new TwoWheeler();
    }
};

// Concrete Factory for FourWheeler
class FourWheelerFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new FourWheeler();
    }
};

// Client class
class Client {
private:
    Vehicle* pVehicle;

public:
    Client(VehicleFactory* factory) {
        pVehicle = factory->createVehicle();
    }

    ~Client() {
        delete pVehicle; // Clean up dynamically allocated memory
    }

    Vehicle* getVehicle() {
        return pVehicle;
    }
};

// Driver program
int main() {
    // Create the factory for TwoWheeler
    VehicleFactory* twoWheelerFactory = new TwoWheelerFactory();
    Client twoWheelerClient(twoWheelerFactory);
    Vehicle* twoWheeler = twoWheelerClient.getVehicle();
    twoWheeler->printVehicle();

    // Create the factory for FourWheeler
    VehicleFactory* fourWheelerFactory = new FourWheelerFactory();
    Client fourWheelerClient(fourWheelerFactory);
    Vehicle* fourWheeler = fourWheelerClient.getVehicle();
    fourWheeler->printVehicle();

    // Clean up factories
    delete twoWheelerFactory;
    delete fourWheelerFactory;

    return 0;
}
