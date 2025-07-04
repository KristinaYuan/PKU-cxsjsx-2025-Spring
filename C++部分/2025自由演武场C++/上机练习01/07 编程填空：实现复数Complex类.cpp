#include <iostream>
using namespace std;

class Complex{
private:
	int real,imag;
public:
	Complex(const char* s):real(s[0]-'0'),imag(s[2]-'0'){}
	Complex(const Complex& other):real(other.real),imag(other.imag){}
	Complex(int r=0, int i=0):real(r),imag(i){}
	friend ostream& operator<< (ostream& os, const Complex& obj){
		if (obj.real!=0){
			os<<obj.real;
		}
		if (obj.real!=0 && obj.imag!=0){
			os<<"+";
		}
		if (obj.imag!=0){
			os<<obj.imag<<"i";
		}
		if (obj.real==0 && obj.imag==0){
			os<<"0";
		}
		return os;
	}
	Complex operator+ (const Complex& other){
		return Complex(real+other.real,imag+other.imag);
	}
	Complex operator- (const Complex& other){
		return Complex(real-other.real,imag-other.imag);
	}
	Complex operator* (const Complex& other){
		return Complex(real*other.real-imag*other.imag,real*other.imag+imag*other.real);
	}
	Complex& operator+= (const Complex& other){
		real+=other.real;
		imag+=other.imag;
		return *this;
	}
	Complex& operator-= (const Complex& other){
		real-=other.real;
		imag-=other.imag;
		return *this;
	}
	Complex& operator*= (const Complex& other){
		int tmp=real*other.real-imag*other.imag;
		imag=real*other.imag+imag*other.real;
		real=tmp;
		return *this;
	}
};

int main() {
	Complex c1;
	Complex c2("3+2i"); // 用字符串初始化时，只需考虑"a+bi"的形式，其中a和b都是1位数字
	Complex c3(c2);
	Complex c4(-15);
	cout << c2 << endl;
	cout << c3 << endl;
	cout << c4 << endl;
	cout << c2 + c4 << endl;
	cout << c2 - c3 << endl;
	cout << c2 * c3 << endl;
	c2 += c4;
	cout << c2 << endl;
	c2 -= -12;
	cout << c2 << endl;
	c3 *= c3;
	cout << c3 << endl;
	return 0;
}
