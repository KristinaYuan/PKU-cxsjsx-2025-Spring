#include <iostream>
#include <queue>
#include <map>
using namespace std;

class cmp{
public:
	bool operator() (const pair<int,int>& a, const pair<int,int>& b) const{
		return a.first>b.first;
	}
};

int main()
{
	priority_queue<pair<int,int>,vector< pair<int,int> >,cmp> oil;
	int n;
	cin>>n;
	string s;
	for (int i=0;i<n;i++){
		cin>>s;
		if (s=="SELL"){
			int x,y;
			cin>>x>>y;
			pair<int,int> tmp;
			tmp.first=y,tmp.second=x;
			oil.push(tmp);
		}
		else if (s=="BUY"){
			int z;
			cin>>z;
			int sum=0;
			while (!oil.empty()){
				if (oil.top().second<=z){
					sum+=oil.top().first*oil.top().second;
					z-=oil.top().second;
					oil.pop();
				}
				else{
					sum+=oil.top().first*z;
					pair<int,int> tmp;
					tmp.first=oil.top().first,tmp.second=oil.top().second-z;
					oil.pop();
					oil.push(tmp);
					z=0;
					break;
				}
			}
			sum+=z*40;
			cout<<sum<<endl;
		}
	}
	return 0;
} 
