#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	map<int, int> members;
	members[1000000000] = 1;
	int id, power;
	for (int t = 0; t < n; t++) {
		cin >> id >> power;
		auto i = members.upper_bound(power);
		auto j = members.lower_bound(power);
		int k;
		if (i == members.end()) {
			j--;
			k = j->second;
		}
		else if (j == members.begin()) {
			k = i->second;
		}
		else {
			j = i;
			j--;
			int a = abs(i->first - power);
			int b = abs(j->first - power);
			if (a < b) {
				k = i->second;
			}
			else if (a > b) {
				k = j->second;
			}
			else if (i->first < power) {
				k = i->second;
			}
			else {
				k = j->second;
			}
		}
		cout << id << " " << k << endl;
		members[power] = id;
	}
	return 0;
}
