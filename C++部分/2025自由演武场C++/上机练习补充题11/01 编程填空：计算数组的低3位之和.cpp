#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class CMy_add{
private:
	int& sum;
public:
	CMy_add(int& x):sum(x){}
	void operator() (int k){
		sum+=k%8;
	}
};

int main(int argc, char* argv[]) {
	int  v, my_sum=0;
	vector<int> vec;		
	cin>>v;
	while ( v ) {
		vec.push_back(v);
		cin>>v;
	}
	for_each(vec.begin(), vec.end(), CMy_add(my_sum));
	cout<<my_sum<<endl;	
	return 0;
}
