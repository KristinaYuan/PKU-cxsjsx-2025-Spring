#include <iostream>
using namespace std;
int gcd(int x, int y){
	return x%y==0?y:gcd(y,x%y);
}
class Fraction
{
    int num, den;
public:

	Fraction(int n=0,int d=1):num(n),den(d){}
	Fraction& operator*= (const Fraction& other){
		num*=other.num;
		den*=other.den;
		int tmp=gcd(num,den);
		num/=tmp;
		den/=tmp;
		return *this;
	}
	Fraction& operator/= (const Fraction& other){
		num*=other.den;
		den*=other.num;
		int tmp=gcd(num,den);
		num/=tmp;
		den/=tmp;
		return *this;
	}
	Fraction operator* (const Fraction& other){
		int n=num*other.num;
		int d=den*other.den;
		int tmp=gcd(num,den);
		n/=tmp;
		d/=tmp;
		return Fraction(n,d);
	}
	Fraction operator/ (const Fraction& other){
		int n=num*other.den;
		int d=den*other.num;
		int tmp=gcd(num,den);
		n/=tmp;
		d/=tmp;
		return Fraction(n,d);
	}
	friend ostream& operator<< (ostream& os, const Fraction& obj){
		os<<obj.num<<"/"<<obj.den;
		return os;
	}
	operator float(){
		return 1.0*num/den;
	}
};
 
int main() {
	int a,b,c;
	cin >> a >> b >> c;
    Fraction f(a, b), g(c);
	f *= g;
	cout << f << endl;
	f /= g;
	cout << f << endl;
	f = f * f;
	cout << f << endl;
	f = f / g;
	cout << f << endl;
	cout << (float) f << endl;
    return 0;
}
