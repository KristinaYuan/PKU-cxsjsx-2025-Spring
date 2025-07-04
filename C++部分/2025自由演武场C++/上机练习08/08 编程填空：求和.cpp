#include <iostream>
using namespace std;
class C {
public:
  static int num;
  int curr_value;
  friend ostream& operator << (ostream& o, const C& c) = delete;
  friend ostream& operator << (ostream& o, C& c) {
    o << "() called " << num << " times, sum is " << c.curr_value;
    return o;
  }
    C(int x = 0) :curr_value(x) {}
    C& operator() (int x) {
        if (num == 2 || num == 3) {
            curr_value = 0;
        }
        num += 1;
        curr_value += x;
        return *this;
    }
    C& operator() (int x, int y) {
        if (num == 2 || num == 3) {
            curr_value = 0;
        }
        num += 1;
        curr_value += (x + y);
        return *this;
    }
};
int C::num = 0;
int main() {
  C c1;
  cout << c1(1)(2) << endl;
  cout << c1(3, 4) << endl;
  cout << c1(5, 6)(7) << endl;
  C c2;
  cout << c2(7)(8, 9) << endl;
  return 0;
}
