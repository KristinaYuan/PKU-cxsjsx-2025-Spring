#include <iostream>
using namespace std;

class A {
public:
	int val;
	A(int n=0):val(n){}
	A& getValue(){
		return *this;
	}
	A& operator+= (const A& other){
		val+=other.val;
		return *this;
	}
	A& operator-= (const A& other){
		val-=other.val;
		return *this;
	}
	operator int(){
		return val;
	}
};

int main() {
	int t;
	cin >> t;
	while(t-- ) {
		int m,n,k;
		cin >> m >> n >> k;	
	    A a(m);
	    A b = a;
	    cout << b << endl;
	    cout << (a += b -= n) << endl;
	    cout << a.getValue() << endl;
	    a.getValue() = k;
	    cout << a << endl;
	} 
	return 0;
}
