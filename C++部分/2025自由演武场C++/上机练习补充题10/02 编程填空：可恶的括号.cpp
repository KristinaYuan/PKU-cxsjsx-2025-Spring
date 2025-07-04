#include <cstdio>
#include <iostream>
using namespace std;

class f {
private:
	int a,b;
public:
	f(int x,int y=0):a(x),b(y){}
	operator int() {
		return a*b;
	}
	int operator() (int y){
		return y-a;
	}
};

int main() {
  cout << f(3)(5) << endl;
  cout << f(4)(10) << endl;
  cout << f(114)(514) << endl;
  cout << f(9,7) << endl;
  cout << f(2,3) << endl;
  cout << f(2,5) << endl;
}
