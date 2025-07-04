#include <iostream>
using namespace std;

class A {
public:
    static int total;
    A() {
        total += 1;
    }
    A(int a) {
        total += a;
    }
    A(int a, int b) {
        total += a * b;
    }
    A(const A& other) {
        total += 1;
    }
    ~A() {
        total -= 1;
    }
};

int A::total = 0;

int main() {
    A array1[4];
    cout << A::total << "\n";
    A array2[4] = { 1, A(1,1) };
    cout << A::total << "\n";
    A a(array1[0]);
    cout << A::total << "\n";
    A* p = new A();
    cout << A::total << "\n";
    delete p;
    cout << A::total << "\n";
    return 0;
}
