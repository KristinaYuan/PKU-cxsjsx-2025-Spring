#include <iostream>
#include <string>
using namespace std;

class MyCout {
public:
    static int sum;
    MyCout& operator<< (int n) {
        sum += n;
        return *this;
    }
    ~MyCout() {
        cout << sum << endl;
    }
};
int MyCout::sum = 0;

int main() {
    MyCout mycout;
    int n;
    while (cin >> n)
        mycout << n;
    return 0;
}
