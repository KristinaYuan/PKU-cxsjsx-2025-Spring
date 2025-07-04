#include <iostream>
#include <list>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	unordered_map<int, vector<int> > x;
	string s;
	int id, id1, id2, num;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "new") {
			cin >> id;
			x[id] = vector<int>();
		}
		if (s == "add") {
			cin >> id >> num;
			x[id].push_back(num);
		}
		if (s == "merge") {
			cin >> id1 >> id2;
			if (id1 != id2) {
				for (vector<int>::iterator j = x[id2].begin(); j != x[id2].end(); j++) {
					x[id1].push_back(*j);
				}
				x[id2].clear();
			}			
		}
		if (s == "unique") {
			cin >> id;
			sort(x[id].begin(), x[id].end());
			x[id].erase(unique(x[id].begin(), x[id].end()), x[id].end());
		}
		if (s == "out") {
			cin >> id;
			sort(x[id].begin(), x[id].end());
			for (vector<int>::iterator j = x[id].begin(); j != x[id].end(); j++) {
				if (j != x[id].begin()) {
					cout << " ";
				}
				cout << *j;
			}
			cout << endl;
		}
	}
	return 0;
}
