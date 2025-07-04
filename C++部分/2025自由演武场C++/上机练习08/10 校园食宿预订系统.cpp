#include <iostream>
#include <map>
using namespace std;

struct dish {
	int price, amount;
};

int main()
{
	int n, m;
	cin >> n >> m;
	map<string, dish> cuisine;
	string s;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> s >> a >> b;
		dish tmp;
		tmp.price = a, tmp.amount = b;
		cuisine[s] = tmp;
	}
	int ans = 0;
	for (int i = 0; i < n * 3; i++) {
		cin >> s;
		if (cuisine[s].amount > 0) {
			ans += cuisine[s].price;
			cuisine[s].amount -= 1;
		}
	}
	cout << ans << endl;
	return 0;
}
