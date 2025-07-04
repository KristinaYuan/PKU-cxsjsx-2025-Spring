#include<iostream>
#include<vector>
using namespace std;
class A{
private:
	int val;
public:
	static int presum;
	A(int x):val(x){
	}
	void output(){
		presum+=val;
		cout<<presum<<endl;
	}
};
int A::presum=0;
int main(){
  int n;cin>>n;
  vector<A*> p;
  for(int i=0;i<n;i++){
    int x;cin>>x;
    p.push_back(new A(x));
  }
  for(int i=0;i<n;i++){
    p[i]->output();
  }
  return 0;
}
