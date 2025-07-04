#include <iostream>
using namespace std;
template <typename T, typename F>
T sum(T* beg, int x, F func) {
    T ans = T{};
    for (int i = 0; i < x; i++) {
        ans += func(*(beg + i));
    }
    return ans;
}
int sqr(int n) {
    return n * n;
}
int main() {
    int t, n, a[0x100];
    cin >> t;
    for (int c = 0; c < t; ++c) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << sum(a, n, sqr) << endl;
    }
    return 0;
}
