#include <iostream>
#include <iterator>
using namespace std;

template<class T1, class T2>
void Copy(T1 s, T1 e, T2 x) {
    for(; s != e; ++s, ++x)
        *x = *s;
}
class Fib {
private:
	int index;
	int mx;
	int n, n2;
public:
	Fib(int k):mx(k),index(1),n(1),n2(1) {}
	Fib& operator++ () {
		int tmp = n + n2;
		n = n2;
		n2 = tmp;
		index += 1;
		return *this;
	}
	int operator* () {
		return n;
	}
	bool operator!= (const Fib& other) {
		return index != other.mx;
	}
};
int main() {
	while(true) {
		int n;
		cin >> n;
		if(n == 0)
			break;
		
	    Fib f1(1), f2(n);
	    ostream_iterator<int> it(cout, " ");
	    Copy(f1, f2, it);
	    cout << endl;
	}
	return 0;
}
