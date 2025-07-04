#include<iostream>
using namespace std;
int count(unsigned int x) {
	int ans = 0;
	while (x) {
		ans += x % 2;
		x /= 2;
	}
	return ans;
}
int main() {
	int T; cin >> T;
	while (T--) {
		unsigned x; cin >> x;
		cout << count(x) << endl;
	}
	return 0;
}
