#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
private:
	int r,c;
	int* ptr;
public:
	Array2(int row=0,int col=0):r(row),c(col){
		ptr=new int[r*c];
	}
	~Array2(){
		delete []ptr;
	}
	Array2(const Array2& other):r(other.r),c(other.c){
		ptr=new int[other.r*other.c];
	}
	Array2& operator=(const Array2& other){
		if (this==&other){
			return *this;
		}
		delete []ptr;
		r=other.r;
		c=other.c;
		ptr=new int[other.r*other.c];
		memcpy(ptr,other.ptr,r*c*sizeof(int));
		return *this;
	}
	int& operator() (int x,int y){
		return ptr[x*c+y];
	}
	class A{
	private:
		int *array;
	public:
		A(int* p):array(p){}
		int& operator[] (int x){
			return array[x];
		}
	};
	A operator[] (int y){
		return A(ptr+y*c);
	}
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
