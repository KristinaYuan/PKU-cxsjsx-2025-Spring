#include <iostream>
using namespace std;

class A {
private:
    int v;
public:
    A() { v = 1; }
    void printV() {
        cout << v * 2 << endl;
    }
    void printV() const {
        cout << v << endl;
    }
};


int main() {
    const A obj1;
    A obj2;

    obj1.printV();
    obj2.printV();

    A* p1 = (A*)(&obj1);
    A* p2 = &obj2;

    p1->printV();
    p2->printV();

    return 0;
}
