#include <iostream>
using namespace std;

class A {
private:
    int val;
public:
    A(int v):val(v){}
    virtual int& get_value() {
        return val;
    }
    A operator+ (A* other) {
        return A(val + other->get_value());
    }
    A* operator-> () {
        return this;
    }
};

class B :public A {
public:
    B(int v):A(v){}
};

class C :public A {
public:
    C(int v):A(v){}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int aa, bb, cc;
        cin >> aa >> bb >> cc;
        A a(aa);
        B b(bb);
        C c(cc);
        A* x = &a;
        A* y = &b;
        A* z = &c;
        cout << (x->get_value() + y->get_value() + z->get_value()) << " ";
        cout << ((*x) + y + z)->get_value() << endl;
    }
    return 0;
}
