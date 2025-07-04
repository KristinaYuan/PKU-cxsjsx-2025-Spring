#include <iostream>
#include <cstring>
using namespace std;
template <int bitNum>
struct MyBitset
{
	char a[bitNum / 8 + 1];
	MyBitset() { memset(a, 0, sizeof(a)); };
	void Set(int i, int v) {
		char& c = a[i / 8];
		int bp = i % 8;
		if (v)
			c |= (1 << bp);
		else
			c &= ~(1 << bp);
	}
	struct reference {
		char& c;
		int bp;
		reference(char& cc, int b) :c(cc), bp(b) {}
		reference& operator=(int v) {
			if (v)
				c |= (1 << bp);
			else
				c &= ~(1 << bp);
			return *this;
		}
		reference& operator=(const reference& r) {
			return *this = int(r);
		}
		operator int() const {
			return (c >> bp) & 1;
		}
	};
	reference operator[](int i) {
		return reference(a[i / 8], i % 8);
	}
	void Print() {
		for (int i = 0; i < bitNum; ++i)
			cout << (*this)[i];
		cout << endl;
	}

};

int main()
{
	int n;
	int i, j, k, v;
	while (cin >> n) {
		MyBitset<20> bs;
		for (int i = 0; i < n; ++i) {
			int t;
			cin >> t;
			bs.Set(t, 1);
		}
		bs.Print();
		cin >> i >> j >> k >> v;
		bs[k] = v;
		bs[i] = bs[j] = bs[k];
		bs.Print();
		cin >> i >> j >> k >> v;
		bs[k] = v;
		(bs[i] = bs[j]) = bs[k];
		bs.Print();
	}
	return 0;
}
