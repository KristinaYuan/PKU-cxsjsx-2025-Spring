#include <iostream>
using namespace std;
class MyCin
{
private:
	int status;
public:
	MyCin():status(true){}
	MyCin& operator>>(int& n){
		if (status==false){
			return *this;
		}
		cin>>n;
		if (n==-1){
			status=false;
		}
		else{
			status=true;
		}
		return *this;
	}
	operator bool() const{
		return status;
	}
};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2) 
        cout  << n1 << " " << n2 << endl;
    return 0;
}
