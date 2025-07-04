#include <iostream>
using namespace std;
class A{
protected:
    int x;
public:
    A(int a=1){
        cout << "construct A" << endl;
        x = a;
    }
    virtual void show(){
        cout << "A:"  << x << endl;
    }
};

class B :public A {
public:
    B(int b = 2):A(b){}
    void show() {
        cout << "B:" << x << endl;
        A::show();
    }
};

class C :public A {
public:
    C(int c = 3) :A(c) {}
    void show() {
        cout << "C:" << x << endl;
        A::show();
    }
};

int main(){
    A a, *pa;
    B b;
    C c;
    pa = &a; pa->show();
    pa = &b; pa->show();
    pa = &c; pa->show();
}
