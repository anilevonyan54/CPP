#include <iostream>
using namespace std;

// Strategy Interface
class Greeting {
public:
    virtual void greet() = 0;
};

// Concrete Strategy 1: GoodMorning
class GoodMorning : public Greeting {
public:
    void greet() override {
        cout << "Good morning." << endl;
    }
};

// Concrete Strategy 2: GoodEvening
class GoodEvening : public Greeting {
public:
    void greet() override {
        cout << "Good evening." << endl;
    }
};

// Context Class
class Greeter {
private:
    Greeting* greetingStrategy; // Reference to strategy

public:
    // Constructor to set the initial greeting strategy
    Greeter(Greeting* strategy) : greetingStrategy(strategy) {}

    // Method to execute the current greeting strategy
    void executeGreeting() {
        greetingStrategy->greet();
    }

    // Method to change the greeting strategy at runtime
    void setGreetingStrategy(Greeting* strategy) {
        greetingStrategy = strategy;
    }
};

int main() {
    // Create a Greeter object with the GoodMorning strategy
    Greeter greeter(new GoodMorning());
    greeter.executeGreeting();  // Outputs: Good morning.

    // Change the strategy to GoodEvening
    greeter.setGreetingStrategy(new GoodEvening());
    greeter.executeGreeting();  // Outputs: Good evening.

    return 0;
}
