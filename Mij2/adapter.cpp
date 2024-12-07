#include <iostream>
using namespace std;

class OldPrinter {
public:
   virtual void oldPrint() {
        cout << "printing with the old printer";
    }
};

class NewPrinter {
public:
    void newPrint() {
        cout << "printing with the new printer";
    }
};

class PrinterAdapter : public OldPrinter {
private:
    NewPrinter* newPrinter;
public:
    PrinterAdapter(NewPrinter* printer) {
        newPrinter = printer;
    }

    void oldPrint() override {
        newPrinter->newPrint(); 
    }
};

int main() {
    NewPrinter* newPrinter = new NewPrinter();
    OldPrinter* Adapter = new PrinterAdapter(newPrinter);
    Adapter->oldPrint();
    delete newPrinter;
    return 0;
}
