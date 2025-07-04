#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
private:
	string num; //ÄæÐò´æ´¢ 
	int len;
public:
	CHugeInt(const char* str){
		num="";
		for (int i=strlen(str)-1;i>=0;i--){
			num+=str[i];
		}
		len=strlen(str);
	}
	CHugeInt(int x){
		num="";
		for (len=0;;len++){
			if (x==0){
				break;
			}
			char c=x%10+'0';
			num+=c;
			x/=10;
		}
	}
	CHugeInt():num(""),len(0){}
	friend ostream& operator<< (ostream& os, const CHugeInt& obj){
		for (int i=obj.len-1;i>=0;i--){
			os<<obj.num[i];
		}
		return os;
	}
	CHugeInt operator+ (const CHugeInt& other){
		int M=max(len,other.len);
		int m=min(len,other.len);
		CHugeInt ans;
		bool plus=0;
		for (int i=0;i<m;i++){
			ans.len+=1;
			if (num[i]-'0'+other.num[i]-'0'+plus<=9){
				ans.num+=num[i]-'0'+other.num[i]-'0'+plus+'0';
				plus=0;
			}
			else{
				ans.num+=num[i]-'0'+other.num[i]-'0'+plus+'0'-10;
				plus=1;
			}
		}
		if (len<other.len){
			for (int i=m;i<M;i++){
				ans.len+=1;
				if (other.num[i]-'0'+plus<=9){
					ans.num+=other.num[i]-'0'+plus+'0';
					plus=0;
				}
				else{
					ans.num+=other.num[i]-'0'+plus+'0'-10;
					plus=1;
				}
			}
		}
		if (len>other.len){
			for (int i=m;i<M;i++){
				ans.len+=1;
				if (num[i]-'0'+plus<=9){
					ans.num+=num[i]-'0'+plus+'0';
					plus=0; 
				}
				else{
					ans.num+=num[i]-'0'+plus+'0'-10;
					plus=1;
				}
			}
		}
		if (plus==1){
			ans.num+='1';
			ans.len+=1;
		}
		return ans;
	}
	friend CHugeInt operator+ (int n, const CHugeInt& obj){
		CHugeInt tmp(n);
		return tmp+obj;
	}
	CHugeInt operator+ (int n){
		CHugeInt tmp(n);
		return *this+tmp;
	}
	CHugeInt& operator+= (int n){
		CHugeInt tmp(n);
		*this=*this+tmp;
		return *this;
	}
	CHugeInt& operator++ (){
		CHugeInt tmp(1);
		*this=*this+tmp;
		return *this;
	}
	CHugeInt operator++ (int){
		CHugeInt tmp(*this);
		*this+=1;
		return tmp;
	}
};
int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);
		
		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}
