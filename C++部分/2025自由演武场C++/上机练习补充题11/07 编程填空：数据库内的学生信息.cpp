#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;

template <class Key,class Val,class Comp=greater<Key>>
class MyMultimap {
private:
	multimap<Key,Val,Comp> m;
public:
	typedef typename multimap<Key, Val, Comp>::iterator iterator;
	void insert(pair<Key, Val> other) {
		m.insert(other);
	}
	iterator begin() {
		return m.begin();
	}
	iterator end() {
		return m.end();
	}
	void Set(Key k, Val v) {
		for (auto i = m.begin(); i != m.end(); i++) {
			if (i->first == k) {
				i->second = v;
			}
		}
	}
	void clear() {
		multimap<Key, Val, Comp> n;
		m = n;
	}
	iterator find(Key k) {
		return m.find(k);
	}
};

template <class Key,class Val>
ostream& operator<< (ostream& os, const pair<Key, Val>& other) {
	os << "(" << other.first << "," << other.second << ")";
	return os;
}

struct Student
{
	string name;
	int score;
};
template <class T>
void Print(T first, T last) {
	for (; first != last; ++first)
		cout << *first << ",";
	cout << endl;
}
int main()
{

	Student s[] = { {"Tom",80},{"Jack",70},
					{"Jone",90},{"Tom",70},{"Alice",100} };

	MyMultimap<string, int> mp;
	for (int i = 0; i < 5; ++i)
		mp.insert(make_pair(s[i].name, s[i].score));
	Print(mp.begin(), mp.end()); //�������Ӵ�С���

	mp.Set("Tom", 78); //��������Ϊ"Tom"��ѧ���ĳɼ�������Ϊ78
	Print(mp.begin(), mp.end());



	MyMultimap<int, string, less<int> > mp2;
	for (int i = 0; i < 5; ++i)
		mp2.insert(make_pair(s[i].score, s[i].name));

	Print(mp2.begin(), mp2.end()); //���ɼ���С�������
	mp2.Set(70, "Error");          //�����гɼ�Ϊ70��ѧ�������ֶ���Ϊ"Error"
	Print(mp2.begin(), mp2.end());
	cout << "******" << endl;

	mp.clear();

	string name;
	string cmd;
	int score;
	while (cin >> cmd) {
		if (cmd == "A") {
			cin >> name >> score;
			if (mp.find(name) != mp.end()) {
				cout << "erroe" << endl;
			}
			mp.insert(make_pair(name, score));
		}
		else if (cmd == "Q") {
			cin >> name;
			MyMultimap<string, int>::iterator p = mp.find(name);
			if (p != mp.end()) {
				cout << p->second << endl;
			}
			else {
				cout << "Not Found" << endl;
			}
		}
	}
	return 0;
}
