#include <iostream>
using namespace std;

class CType{
private:
	int val;
public:
	void setvalue(int n){
		val=n;
	}
	friend ostream& operator<< (ostream& os, const CType& obj){
		os<<obj.val;
		return os;
	}
	CType operator++ (int){
		CType tmp(*this);
		val=val*val;
		return tmp;
	}
};

int main(int argc, char* argv[]) {
	CType obj;
	int   n;		
	cin>>n;
	while ( n ) {
		obj.setvalue(n);
		cout<<obj++<<" "<<obj<<endl;
		cin>>n;
	}
	return 0;
}
