#include <iostream>
#include <set>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
class MyFunc{
public:
	int rep;
	T& res;
	T tmp;
	bool c;
	MyFunc(int repeat, T& result):rep(repeat),res(result),tmp(),c(0){}
	MyFunc(const MyFunc<T>& other):rep(other.rep),res(other.res),tmp(other.tmp),c(1){}
	void operator() (const T& val){
		res+=val;
		tmp+=val;
	}
	~MyFunc(){
		if (c==0){
			for (int i=1;i<rep;i++){
				res+=tmp;
			}
		}
	}
};

int main(){
    vector<int> v1;
    vector<string> v2;
    int N, val, num_repeat,result_int=0;
    string str,result_str="";
    cin>>N;
    cin>>num_repeat;
    for(int i=0;i<N;++i){
        cin>>val;
        v1.push_back(val);
    }
    for_each(v1.begin(),v1.end(),MyFunc<int>(num_repeat,result_int));
    for(int i=0;i<N;++i){
        cin>>str;
        v2.push_back(str);
    }
    for_each(v2.begin(),v2.end(),MyFunc<string>(num_repeat,result_str));
    cout<<result_int<<endl;
    cout<<"--------------"<<endl;
    cout<<result_str<<endl;
}
