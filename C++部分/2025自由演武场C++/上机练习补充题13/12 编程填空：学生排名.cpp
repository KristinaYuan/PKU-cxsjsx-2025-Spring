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
typedef pair<string, int> PAIR;
class MyMap :public map<string, int>
{
public:
	friend istream& operator>> (istream& is, MyMap& obj) {
		string s;
		int n;
		is >> s >> n;
		if (!obj.count(s)) {
			obj.insert(PAIR{ s,n });
		}
		return is;
	}
	friend ostream& operator<< (ostream& os, const MyMap& obj) {
		vector<PAIR> stu(obj.begin(), obj.end());
		sort(stu.begin(), stu.end(), [](const PAIR& a, const PAIR& b) {
			if (a.second != b.second) {
				return a.second > b.second;
			}
			else if (a.first.length() != b.first.length()) {
				return a.first.length() < b.first.length();
			}
			return a.first < b.first;
			});
		for (auto it = stu.begin(); it != stu.end(); it++) {
			os << it->first << " " << it->second << endl;
		}
		return os;
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		MyMap mm;
		for (int i = 0; i < n; ++i)
			cin >> mm;
		cout << mm;

	}
	return 0;
}
