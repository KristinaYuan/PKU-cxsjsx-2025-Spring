#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;

class A{
public:
	int age;
	A(int k):age(k){}
	virtual void print(){
		cout<<"A "<<age<<endl;
	}
};

class B:public A{
public:
	B(int k):A(k){}
	void print(){
		cout<<"B "<<age<<endl;
	}
};

class Comp{
public:
	bool operator() (A* a, A* b) const{
		return a->age<b->age;
	}
};

void Print(A* a){
	a->print();
}

int main()
{

	int t;
	cin >> t;
	set<A*,Comp> ct;
	while( t -- ) {
		int n;
		cin >> n;
		ct.clear();
		for( int i = 0;i < n; ++i)	{
			char c; int k;
			cin >> c >> k;
			
			if( c == 'A')
				ct.insert(new A(k));
			else
				ct.insert(new B(k));
		}	
		for_each(ct.begin(),ct.end(),Print);
		cout << "****" << endl;
	}
}
