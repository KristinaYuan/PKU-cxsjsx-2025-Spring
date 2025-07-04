#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>
using namespace std;
template <typename T>
class Print {
private:
	int cnt;
	int s;
public:
	Print(int x):cnt(0),s(x){}
	Print operator+ (const T& t) {
		cout << t;
		cnt += 1;
		if (cnt == s) {
			cout << endl;
		}
		return *this;
	}
};
int main(){
	string s[20];
	int num[20];
	int m,n;
	
	while(cin >> m >> n){
		for(int i=0; i<m; i++){
			cin >> s[i];
		}
		accumulate(s, s+m, Print<string>(m));
		for(int i=0; i<n; i++){
			cin >> num[i];
		}
		accumulate(num, num+n, Print<int>(n));
	}
}
