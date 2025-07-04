#include <iostream>
#include <set>
using namespace std;

class Rectangle {
public:
    int h, w;
    Rectangle(int a,int b):h(a),w(b){}
    bool operator< (const Rectangle& other) const{
        if (h * w != other.h * other.w) {
            return h * w > other.h * other.w;
        }
        return h + w > other.h + other.w;
    }
    friend ostream& operator<< (ostream& os, const Rectangle& obj) {
        os << obj.h * obj.w << " " << 2 * (obj.h + obj.w);
        return os;
    }
};

class Comp {
public:
    bool operator() (const Rectangle& x, const Rectangle& y) const{
        if (x.h + x.w != y.h + y.w) {
            return x.h + x.w < y.h + y.w;
        }
        return x.h * x.w < y.h * y.w;
    }
};

int main() {
    multiset<Rectangle> m1;
    multiset<Rectangle, Comp> m2;
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        m1.insert(Rectangle(a, b));
        m2.insert(Rectangle(a, b));
    }
    for (multiset<Rectangle>::iterator it = m1.begin(); it != m1.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;
    for (multiset<Rectangle>::iterator it = m2.begin(); it != m2.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}
