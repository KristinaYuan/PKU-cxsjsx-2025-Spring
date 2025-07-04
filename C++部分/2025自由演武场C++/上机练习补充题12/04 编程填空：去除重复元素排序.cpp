#include <iterator>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <iostream>
#include <set>
using namespace std;

int main() {
	int t;
	int  a[100];
	cin >> t;
	while(t--) {
		for(int i = 0;i < 12; ++i)
			cin >> a[i];
		vector<int> b(a,a+12);
		sort(b.begin(),b.end());
		b.erase(unique(b.begin(),b.end()),b.end());
		ostream_iterator<int> c(cout," ");
		std::copy(b.begin(), b.end(), c);
		cout << endl;

	}
	return 0;
}
