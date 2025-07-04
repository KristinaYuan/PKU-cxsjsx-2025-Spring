#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_map<int, int> data;
	int n;
	cin >> n;
	string s;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> s >> num;
		if (s == "add") {
			data[num] += 1;
			cout << data[num] << endl;
		}
		if (s == "del") {
			if (data.find(num) != data.end()) {
				cout << data[num] << endl;
				data[num] = 0;
			}
			else {
				cout << "0" << endl;
			}
		}
		if (s == "ask") {
			if (data.find(num) == data.end()) {
				cout << "0 0" << endl;
			}
			else {
				cout << "1 " << data[num] << endl;
			}
		}
	}
	return 0;
}
