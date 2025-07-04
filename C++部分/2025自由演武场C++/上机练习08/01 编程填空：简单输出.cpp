#include <iostream>
using namespace std;
class A {
	public:
	int val;
	void print() {
		cout << val << endl;
	}
	A(int v=100):val(v){}
	A(const A& other):val(2*other.val){}
};
int main()
{
	int n;
	cin >> n;
	A a(n),b(a),c;
	a.print();  //��� n 
	b.print();  //��� 2n 
	c.print();  //���100 
	return 0;
}
