#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

class MyMap{
public:
    map<int, map<string, bool>> val;
    friend istream& operator>> (istream& is, MyMap& mm) {
        string s;
        int n;
        cin >> s >> n;
        if (mm.val[-n].count(s) == 0) {
            mm.val[-n][s] = 1;
        }
        return is;
    }
    friend ostream& operator<< (ostream& os, const MyMap& mm) {
        for (auto it = mm.val.begin(); it!= mm.val.end(); it++) {
            cout << -it->first;
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
    cout<<mm;
    return 0; 
}
