#include <iostream>
using namespace std;

class Singleton {
private:
	static Singleton* instance;
	Singleton(){}

public:
	static Singleton* getInstance() {
		if (instance == nullptr) {
			instance = new Singleton;
		}
		return instance;

	}
};
Singleton* Singleton::instance = nullptr;

