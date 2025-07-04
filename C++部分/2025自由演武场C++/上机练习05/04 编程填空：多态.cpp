#include <iostream>
using namespace std;

class Base {
public:
   virtual Base& fun() { cout << "base fun" << endl; return *this; }
   virtual Base& foo() { cout << "base foo" << endl; return *this; }
};

class Derived: public Base {
public:
   Base& fun() { cout << "derived fun" << endl; return *this; }
   Base& foo() { cout << "derived foo" << endl; return *this; }
};

Base& foo();
Base& fun();

Base A;
Derived B;

Base& foo(){
	B.foo();
	return B;
}

Base& fun(){
	A.fun();
	return A;
}

int main() {
   foo().fun().foo();
   fun().foo().fun();
   return 0;
}
