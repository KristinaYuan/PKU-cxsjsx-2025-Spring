#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int fac(int n){
	int cnt=0;
	int tmp=n;
	for (int i=2;i*i<=tmp;i++){
		if (n%i==0){
			cnt+=1;
			while (n%i==0){
				n/=i;
			}
		}
	}
	if (n!=1 && cnt!=0){
		cnt+=1;
	}
	return cnt;
}

struct greaterthan{
	bool operator() (int a,int b){
		if (fac(a)!=fac(b)){
			return fac(a)<fac(b);
		}
		return a<b;
	}
};

struct lesserthan{
	bool operator() (int a,int b){
		if (fac(a)!=fac(b)){
			return fac(a)>fac(b);
		}
		return a>b;
	}
};

int main()
{
	int num;
	cin>>num;
	priority_queue<int,vector<int>,greaterthan> mx;
	priority_queue<int,vector<int>,lesserthan> mn;
	int n;
	for (int i=0;i<num;i++){		
		for (int j=0;j<10;j++){
			cin>>n;
			mx.push(n);
			mn.push(n);
		}
		cout<<mx.top()<<" "<<mn.top()<<endl;
		mx.pop();
		mn.pop();
	}
	return 0;
}
