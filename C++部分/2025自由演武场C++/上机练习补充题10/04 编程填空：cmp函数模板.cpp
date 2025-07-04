#include <vector>
#include <set>
#include <list>
#include <iostream>
using namespace std;

template <class T>
void cmp(T a[],int b){
	cout<<"c"<<endl;
}

template <class T>
void cmp(T a,int& b){
	cout<<"b"<<endl;
}

template <class T1,class T2>
void cmp(T1 a,T2 b){
	cout<<"a"<<endl;
}

int main(){
  int A[100];
  A[0]=1; A[1]=2;
  cmp(A[0],2);
  printf("finish 1\n");
  cmp(1, A[1]);
  printf("finish 2\n");
  cmp(A,A[1]);
  printf("finish 3\n");
}
