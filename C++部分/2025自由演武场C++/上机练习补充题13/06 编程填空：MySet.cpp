#include <set>
#include <iostream>
using namespace std;
template <class T>
class MySet : public set<T> {
public:
	void insert(const T& v) {
		if (this->count(v) == 0) {
			set<T>::insert(v);
		}
		else {
			cout << "Error insert " << v << endl;
		}
	}
	void erase(const T& v) {
		if (this->count(v) != 0) {
			set<T>::erase(v);
		}
		else {
			cout << "Error erase " << v << endl;
		}
	}
};
int main() {
	int n; scanf("%d", &n);
	MySet<int> S;
	for (int i = 1; i <= n; i++) {
		cout << "Operation #" << i << ":" << endl;
		string type; int w;
		cin >> type >> w;
		if (type == "insert") S.insert(w);
		else if (type == "erase") S.erase(w);
	}
	cout << endl;
	MySet<string> S2;
	for (int i = 1; i <= n; i++) {
		cout << "Operation #" << i << ":" << endl;
		string type; string w;
		cin >> type >> w;
		if (type == "insert") S2.insert(w);
		else if (type == "erase") S2.erase(w);
	}
}
