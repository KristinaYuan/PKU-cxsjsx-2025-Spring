#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

template <class T, class F>
T Myaccumulate(T* beg, int x, F func) {
    T ans = T{};
    for (int i = 0; i < x; i++) {
        ans += func(*(beg + i));
    }
    return ans;
}

template <class T>
class MyAccumulate {
public:
    T sum;
    MyAccumulate():sum(T{}){}
    template <class F>
    T operator() (T* beg, int x, F func) {
        T ans = T{};
        for (int i = 0; i < x; i++) {
            ans += func(*(beg + i));
        }
        return ans;
    }
};

int sqr(int n) {
    return n * n;
}
string rev(string s) {
    return string(s.rbegin(), s.rend()); ;
}
int main() {
    int a[100];
    string b[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    cout << Myaccumulate(a, n, sqr) << endl;
    cout << Myaccumulate(b, n, rev) << endl;
    cout << MyAccumulate<int>()(a, n - 1, sqr) << endl;
    cout << MyAccumulate<string>()(b + 1, n - 1, rev) << endl;
    return 0;
}
