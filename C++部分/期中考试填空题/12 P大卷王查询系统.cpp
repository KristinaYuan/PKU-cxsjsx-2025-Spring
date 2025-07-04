#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
using namespace std;

struct info{
	int cnt;
	int total;
};

int main()
{
	int n,x,y;
	cin>>n>>x>>y;
	map<string,info> stu;
	for (int i=0;i<n;i++){
		string c,name;
		int score;
		cin>>c>>name>>score;
		stu[name].cnt+=1;
		stu[name].total+=score;
	}
	int m;
	cin>>m;
	for (int i=0;i<m;i++){
		string s;
		cin>>s;
		if (stu[s].cnt>=x){
			if (1.0*stu[s].total/stu[s].cnt>y){
				cout<<"yes"<<endl;
			}
			else{
				cout<<"no"<<endl;
			}
		}
		else{
			cout<<"no"<<endl;
		}
	}
	return 0;
}
