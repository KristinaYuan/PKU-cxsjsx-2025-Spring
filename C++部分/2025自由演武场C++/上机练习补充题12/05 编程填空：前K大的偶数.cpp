#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <set>

using namespace std;
class MyQueue
{
private:
	priority_queue<int> val;
	int t;
public:
	MyQueue(int k):t(k){}
	friend istream& operator>> (istream& is, MyQueue& obj){
		int x;
		is>>x;
		if (x%2==0){
			obj.val.push(x);
		}
		return is;
	}
	friend ostream& operator<< (ostream& os, MyQueue& obj){
		for (int i=0;i<obj.t;i++){
			if (i>0){
				cout<<" ";
			}
			cout<<obj.val.top();
			obj.val.pop();
		}
		return os;
	}
};
int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		MyQueue q(k);
		for (int i = 0; i < n; ++i)
			cin >> q;
		cout<<q;
		cout << endl;
	}
	return 0; 
}
