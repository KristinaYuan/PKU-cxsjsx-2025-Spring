#include <iostream>
#include <string>
using namespace std;
template <class T>
T SumArray(T* beg, T* end);

template <class T>
T PrintArray(T* beg, T* end){
	if (beg==end){
		return T{};
	}
	return *beg + PrintArray(beg+1, end);
}

template <class T>
T SumArray(T* beg, T* end){
	return PrintArray(beg, end);
}
int main() {
	string array[4] = { "Tom","Jack","Mary","John"};
	cout << SumArray(array,array+4) << endl;
	int a[4] = { 1, 2, 3, 4};  //ÌáÊ¾£º1+2+3+4 = 10
	cout << SumArray(a,a+4) << endl;
	return 0;
}
