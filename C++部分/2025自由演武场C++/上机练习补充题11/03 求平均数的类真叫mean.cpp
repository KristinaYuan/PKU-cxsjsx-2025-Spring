#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class CMean {
private:
	int& mean;
	int sum;
	int cnt;
public:
	CMean(int& n):mean(n),sum(0),cnt(0){}
	void operator() (int k){
		sum+=k;
		cnt+=1;
	}
	~CMean(){
		mean=sum/cnt;
	}
};

int main(int argc, char* argv[]) {
	int  v;
	int t;
	cin >> t;
	while ( t -- ) {
		cin >> v;
		vector<int> vec;
		while (v) {
			vec.push_back(v);
			cin >> v;
		}
		int myAver = 0;
		for_each(vec.begin(), vec.end(), CMean(myAver));
		cout << myAver << endl;
	}
	return 0;
}
