#include <iostream>
using namespace std;


class Singleton {
protected:
	Singleton() = default;

public:
	int data;
	static Singleton& get_instance() {
		static Singleton instance;
		return instance;
	}
};



int main() {

	Singleton &singleton1 = Singleton::get_instance();
	singleton1.data = 20;
	cout << singleton1.data << endl;

	return 0;
}



//tarb 2
#include <iostream>
using namespace std;

class Singleton {
private:
	static Singleton* instance;
	Singleton(){}

public:
	static Singleton* getInstance() {
		return instance;
	}
};
Singleton* Singleton::instance = new Singleton();
