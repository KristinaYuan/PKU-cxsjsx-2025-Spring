#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

template <class T>
struct val {
	T operator() (T x) {
		return x;
	}
};

template <class T, class T2 = val<T>>
class Comparator {
public:
	bool operator() (T a, T b) {
		T2 t;
		if (t(a) != t(b)) {
			return t(a) < t(b);
		}
		return a < b;
	}
};

struct len {
	int operator() (string s){
		return s.length();
	}
};
int main() 
{
	int a[8] {4,2,1,3,5,6,8,7};
	sort(a,a+8,Comparator<int>());
	for( int x : a)
		cout << x << " ";
	cout << endl;
	int n;
	vector<string> v;
	cin >> n;
	for(int i=0;i< n; ++i) {
		string s;
		cin >> s;
		v.push_back(s);
	}			
	sort(v.begin(),v.end(),Comparator<string>());
	for( string x : v)
		cout << x << " ";
	cout << endl;
	
	sort(v.begin(),v.end(),Comparator<string,len>());
	for( string x : v)
		cout << x << " ";
	 
	return 0;
}
