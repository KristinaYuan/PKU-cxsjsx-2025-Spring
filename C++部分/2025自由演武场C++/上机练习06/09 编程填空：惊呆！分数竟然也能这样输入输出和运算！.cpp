#include <iostream>
using namespace std;
int gcd(int a, int b) { // 计算两个数的最大公约数
    return (!b) ? a : gcd(b, a % b);
}
class Fraction {
    int p, q;
public:
    Fraction(int a = 0, int b = 1) {
        int tmp = gcd(a, b);
        p = a / tmp;
        q = b / tmp;
    }
    Fraction operator* (Fraction& other) {
        Fraction ans(1);
        ans.p = p * other.p;
        ans.q = q * other.q;
        int tmp = gcd(ans.p, ans.q);
        ans.p /= tmp;
        ans.q /= tmp;
        return ans;
    }
    Fraction operator* (int n) {
        Fraction ans(p * n, q);
        int tmp = gcd(ans.p, ans.q);
        ans.p /= tmp;
        ans.q /= tmp;
        return ans;
    }
    friend istream& operator>> (istream& is, Fraction& obj) {
        is >> obj.p >> obj.q;
        return is;
    }
    friend ostream& operator<< (ostream& os, const Fraction& obj) {
        int tmp = gcd(obj.p, obj.q);
        int x = obj.p / tmp;
        int y = obj.q / tmp;
        os << x;
        if (y != 1) {
            os << "/" << y;
        }
        return os;
    }
};

int main(){
    int testcases;
    cin >> testcases;
    while (testcases --) {
        Fraction a, b, two(2);
        cin >> a >> b;
        cout << a << " * " << b << " = " << a * b << endl;
        cout << "2 * " << a << " = " << two * a << endl;
        cout << b << " * 3 = " << b * 3 << endl;
    }
    return 0;
}
