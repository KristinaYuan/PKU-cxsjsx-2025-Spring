#include <iostream>
#include <string>
using namespace std;
template <class T> 
class container{
private:
    T val;
public:
    container(const T& x) :val(x) {}
    T operator+ (container& other) {
        return val + other.val + other.val;
    }
    T operator+ (T x) {
        return val + x;
    }
};
int main(){
	int n,m;
	cin >> n >> m;
	string s1,s2;
	cin >> s1 >> s2;
    container <int> a = n;
    container <int> b = m;
    cout<<a+b<<endl;
    cout<<a+m<<endl;
    container <string> sa = string(s1);
    container <string> sb = string(s2);
    cout<<sa+sb<<endl;
    cout<< sa + s2<<endl;
}
