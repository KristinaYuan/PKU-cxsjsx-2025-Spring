#include <iostream>
#include <queue>
using namespace std;

class Comp {
public:
	bool operator() (const pair<int, int>& a, const pair<int, int>& b)const {
		if (a.second != b.second) {
			return a.second < b.second;
		}
		return a.first > b.first;
	}
};

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		priority_queue < pair<int, int>, vector<pair<int, int>>, Comp> q[3];
		string cmd;
		int pri, doc;
		int id = 0;
		for (int i = 0; i < n; i++) {
			cin >> cmd;
			if (cmd == "IN") {
				cin >> doc >> pri;
				id += 1;
				q[doc - 1].push(pair<int, int>{id, pri});
			}
			if (cmd == "OUT") {
				cin >> doc;
				if (q[doc - 1].empty()) {
					cout << "EMPTY" << endl;
				}
				else {
					cout << q[doc - 1].top().first << endl;
					q[doc - 1].pop();
				}
			}
		}
	}
	return 0;
}
