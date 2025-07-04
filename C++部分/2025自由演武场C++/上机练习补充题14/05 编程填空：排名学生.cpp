#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

class MyMap :public map<int,map<string,bool>,greater<int>>{
public:
    friend istream& operator>> (istream& is, MyMap& obj) {
        string s;
        int n;
        is >> s >> n;
        if (obj[n].count(s) == 0) {
            obj[n][s] = 1;
        }
        return is;
    }
    friend ostream& operator<< (ostream& os, const MyMap& obj) {
        for (auto it = obj.begin(); it != obj.end(); it++) {
            cout << it->first;
            for (auto j = it->second.begin(); j != it->second.end(); j++) {
                cout << " " << j->first;
            }
            cout << endl;
        }
        return os;
    }
};
int main()
{
    int n;
    cin >> n;
    MyMap mm;
    for (int i = 0; i < n; ++i)
        cin >> mm;
    cout << mm;
    return 0;
}
