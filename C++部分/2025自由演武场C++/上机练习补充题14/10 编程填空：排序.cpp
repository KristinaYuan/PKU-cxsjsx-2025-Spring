#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <set>

using namespace std;
int main() {
    int x, p;
    cin >> x >> p; //保证 x 有逆元
    int a[10] = { 0,1,2,3,4,9,8,7,6,5 };
    sort(a, a + 10,
        [&p, &x](int m, int n) {
            if (m * x % p != n * x % p) {
                return m * x % p < n * x % p;
            }
            return m < n;
        }
        );

    for (int i = 0; i < 10; i++)cout << a[i] << endl;
}
