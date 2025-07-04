#include <iostream>
using namespace std;
class A {
public:
	~A() {
		cout << "Hello,world!" << endl;
	}
};
A a;
int main() {
	return 0;
}
