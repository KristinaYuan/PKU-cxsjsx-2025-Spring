#include <iostream>
using namespace std;

template <class T>
class Multiply {
public:
    T val;
    Multiply(T v):val(v){}
    int operator() (T a, T b) {
        return (int)(a * b + val);
    }
};
int main() {
    double f;
    int n;
    cin >> f >> n;
    Multiply<double> m1(f);
    Multiply<int> m2(n);
    double x, y;
    int p, q;
    cin >> x >> y >> p >> q;
    cout << m1(x, y) << endl;
    cout << m2(p, q) << endl;
    return 0;
}
