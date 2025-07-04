#include <iostream>
using namespace std;

bool Greater2(int n1,int n2) 
{
	return n1 > n2;
}
bool Greater1(int n1,int n2) 
{
	return n1 < n2;
}
bool Greater3(double d1,double d2)
{
	return d1 < d2;
}

template <class T1,class T2>
void mysort(
T1* beg, T1* end, T2 func){
	bool flag=1;
	while (flag==1){
		flag=0;
		for (T1* i=beg;i<end-1;i++){
			if (func(*(i+1), *i)){
				T1 tmp=*i;
				*i=*(i+1);
				*(i+1)=tmp;
				flag=1;
			}
		}
	}
}
#define NUM 5
int main()
{
    int an[NUM] = { 8,123,11,10,4 };
    mysort(an,an+NUM,Greater1); //��С�������� 
    for( int i = 0;i < NUM; i ++ )
       cout << an[i] << ",";
    mysort(an,an+NUM,Greater2); //�Ӵ�С���� 
    cout << endl;
    for( int i = 0;i < NUM; i ++ )
        cout << an[i] << ","; 
    cout << endl;
    double d[6] = { 1.4,1.8,3.2,1.2,3.1,2.1};
    mysort(d+1,d+5,Greater3); //��������±�1���±�4��С�������� 
    for( int i = 0;i < 6; i ++ )
         cout << d[i] << ","; 
	return 0;
}
