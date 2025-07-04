#include <iostream>
#include <string>
#include <cstring>
using namespace std;
template <class T>  
class myclass {
private:
	T* p;
	int size;
public:
	myclass(T* beg, int N):size(N){
		p=new T[N];
		for (int i=0;i<N;i++){
			p[i]=*(beg+i);
		}
	}
	~myclass( ) {
		delete [] p;
	}
	void Show()
	{
		for( int i = 0;i < size;i ++ ) {
			cout << p[i] << ",";
		}
		cout << endl;
	}
};
int a[100];
int main() {
	char line[100];
	while( cin >> line ) {
		myclass<char> obj(line,strlen(line));;
		obj.Show();
		int n;
		cin >> n;
		for(int i = 0;i < n; ++i)
			cin >> a[i];
		myclass<int> obj2(a,n);
		obj2.Show();
	}
	return 0;
}
