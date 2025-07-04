#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
template <class T>
class CArray3D{
private:
	int layer,row,column;
	T* ptr1;
public:
	CArray3D(int l,int r,int c):layer(l),row(r),column(c){
		ptr1=new T[l*r*c];
	}
	
	class CArray2D{
	private:
		int row,column;
		T* ptr2;
	public:
		CArray2D(int r,int c,T* beg):row(r),column(c),ptr2(beg){}
		
		class CArray1D{
		private:
			int column;
			T* ptr3;
		public:
			CArray1D(int c,T* beg):column(c),ptr3(beg){}
			T& operator[] (int c){
				return ptr3[c];
			}
			operator T*() {
				return ptr3;
			}
		};
		
		CArray1D operator[] (int r){
			return CArray1D(column,ptr2+r*column);
		}
		operator T*() {
			return ptr2;
		}
	};
	
	CArray2D operator[] (int l){
		return CArray2D(row,column,ptr1+l*row*column);
	}
	operator T*() {
		return ptr1;
	}
};

CArray3D<int> a(3,4,5);
CArray3D<double> b(3,2,2);
void PrintA()
{
    for(int i = 0;i < 3; ++i) {
        cout << "layer " << i << ":" << endl;
        for(int j = 0; j < 4; ++j) {
            for(int k = 0; k < 5; ++k)
                cout << a[i][j][k] << "," ;
            cout << endl;
        }
    }
}
void PrintB()
{
    for(int i = 0;i < 3; ++i) {
        cout << "layer " << i << ":" << endl;
        for(int j = 0; j < 2; ++j) {
            for(int k = 0; k < 2; ++k)
                cout << b[i][j][k] << "," ;
            cout << endl;
        }
    }
}

int main()
{
    
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    PrintA();
    memset(a, -1, 60 * sizeof(int));        //×¢ÒâÕâÀï
    memset(a[1][1], 0, 5 * sizeof(int));
    PrintA();
    
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 2; ++j )
            for( int k = 0; k < 2; ++k )
                b[i][j][k] = 10.0 / (i + j + k + 1);
    PrintB();
    int n = a[0][1][2];
    double f = b[0][1][1];
    cout << "****" << endl;
    cout << n << "," << f << endl;
    
    return 0;
}
