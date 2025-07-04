#include <iostream>
#include <string>
using namespace std;

class Slime {
public:
	virtual string name() {
		return "A Slime";
	}
	Slime() {
		cout << "A slime appears...\n";
	}
	virtual ~Slime() {
		cout << "A slime disappears...\n";
	}
	void attack(Slime* obj) {
		cout << name() << " attacked " << obj->name() << endl;
	}
};

class HydroSlime : public Slime {
public:
	string name() { return "Hydro Slime"; }
	HydroSlime() { cout << "A hydro slime appears...\n"; }
	~HydroSlime() { cout << "A hydro slime disappears...\n"; }
};

class PyroSlime : public Slime {
public:
	string name() { return "Pyro Slime"; }
	PyroSlime() { cout << "A pyro slime appears...\n"; }
	~PyroSlime() { cout << "A pyro slime disappears...\n"; }
};

int main() {
	Slime* a = new HydroSlime, * b = new PyroSlime;
	a->attack(b);
	b->attack(a);
	delete a;
	delete b;
	return 0;
}
