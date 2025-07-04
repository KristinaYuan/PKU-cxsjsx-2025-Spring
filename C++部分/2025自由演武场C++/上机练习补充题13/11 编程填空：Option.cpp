#include <iomanip>
#include <iostream>
using namespace std;

class TNone {};
TNone None;

template <class T>
class Option {
private:
    bool isNone;
    T val;
public:
    Option() :isNone(1), val(T{}){}
    Option(T v):isNone(0),val(v){}
    Option(const TNone& n):isNone(1),val(T{}){}
    bool has_value() {
        return 1 - isNone;
    }
    Option& operator= (const Option& other) {
        isNone = other.isNone;
        val = other.val;
        return *this;
    }
    T& operator*() {
        return val;
    }
    const T& operator*() const {
        return val;
    }
    T value() {
        return val;
    }
    operator bool() const{
        return 1 - isNone;
    }
};

int main() {
    cout << boolalpha;

    Option<int> a(0), b, c(1);
    cout << a.has_value() << endl;
    cout << b.has_value() << endl;
    b = a;
    *b += 10;
    cout << a.value() << endl;
    cout << b.value() << endl;
    c = None;
    cout << c.has_value() << endl;

    Option< Option<int> > x = None;
    const Option< Option<int> > y = a;
    Option< Option<int> > z = c;
    if (x)
        cout << "x has value" << endl;
    if (y)
        cout << "y has value" << endl;
    if (z)
        cout << "z has value" << endl;
    x = y;
    x = x;
    *x = b;
    **x = 20;
    cout << x.value().value() + **y << endl;
    return 0;
}
