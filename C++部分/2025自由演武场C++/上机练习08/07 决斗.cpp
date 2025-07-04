#include <iostream>
#include <queue>
using namespace std;

class cmp {
public:
	bool operator() (const pair<string, int>& a, const pair<string, int>& b) const{
		if (a.second != b.second) {
			return a.second < b.second;
		}
		return a.first < b.first;
	}
};

int main()
{
	priority_queue<pair<string, int>, vector<pair<string,int>>, cmp> warrior;
	int n;
	cin >> n;
	int x;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> x >> s;
		warrior.push(pair<string,int> { s,x });
	}
	bool flag = 1;
	auto a = warrior.top();
	while (true) {
		a = warrior.top();
		warrior.pop();
		if (warrior.empty()) {
			break;
		}
		auto b = warrior.top();
		warrior.pop();
		if (a.second != b.second) {
			a = pair<string, int>{ a.first,a.second - b.second };
			warrior.push(a);
		}
		if (warrior.empty()) {
			flag = 0;
			cout << "-1" << endl;
			break;
		}
	}
	if (flag == 1) {
		cout << a.first << endl;
	}
	return 0;
}
