#include <iostream>
#include <cstring> 
#include <vector>
#include <cstdio> 
using namespace std;
template <typename T>
class CMyClass {
private:
	T x[55];
public:
	CMyClass(T* beg, int n) {
		for (int i = 0; i < n; i++) {
			x[i] = *(beg + i);
		}
	}
	T operator[] (int i) {
		return x[i];
	}
};
int  a[40];
int main(int argc, char** argv) {
	int t;
	scanf("%d",&t);
	while ( t -- ) {
		int m;
		scanf("%d",&m);
		for (int i = 0;i < m; ++i) 
			scanf("%d",a+i);
		char s[100];
		scanf("%s",s);
		CMyClass<int> b(a, m);
		CMyClass<char> c(s, strlen(s));
		printf("%d %c\n", b[5], c[7]);
	}
	return 0;
}
