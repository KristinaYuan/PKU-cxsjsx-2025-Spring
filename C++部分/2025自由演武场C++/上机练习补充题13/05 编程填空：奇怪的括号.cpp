#include <cstdio>
#include <iostream>
using namespace std;

class f {
private:
	int n;
public:
	f(int x):n(x){}
	f(int x,int y):n(x*y){}
	f& operator() (int x) {
		n += x;
		return *this;
	}
	operator int() {
		return n;
	}
};

int main() {
	cout << f(4)(5) << endl;
	cout << f(64)(36) << endl;
	cout << f(3)(5)(7) << endl;
	cout << f(3, 8) << endl;
	cout << f(15, 3) << endl;
	cout << f(7, 10) << endl;
}
