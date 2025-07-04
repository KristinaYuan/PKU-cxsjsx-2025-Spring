#include <iostream>
#include <map>
using namespace std;

struct info{
	int price;
	int amount;
};

int main()
{
	int n,m;
	cin>>n>>m;
	map<string,info> dish;
	for (int i=0;i<m;i++){
		string s;
		int a,b;
		cin>>s>>a>>b;
		info tmp;
		tmp.price=a,tmp.amount=b;
		dish[s]=tmp;
	}
	int ans=0;
	for (int i=0;i<n*3;i++){
		string s;
		cin>>s;
		if (dish[s].amount>0){
			ans+=dish[s].price;
			dish[s].amount-=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
