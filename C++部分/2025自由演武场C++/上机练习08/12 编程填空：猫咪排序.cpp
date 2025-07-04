#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;

class cat {
public:
    int age, drug;
    cat(int k,int d=0):age(k),drug(d){}
    virtual void print() {
        cout << "cat " << age << endl;
    }
};

class drug_cat :public cat {
public:
    drug_cat(int k, int d):cat(k,d){}
    void print() {
        cout << "drug_cat " << age << " " << drug << endl;
    }
};

class Comp {
public:
    bool operator() (cat* a, cat* b) const{
        if (a->age != b->age) {
            return a->age < b->age;
        }
        return a->drug < b->drug;
    }
};

void Print(cat* x) {
    x->print();
}

int main()
{
    int t, d;
    cin >> t;
    set<cat*, Comp> ct;
    while (t--) {
        int n;
        cin >> n;
        ct.clear();
        for (int i = 0; i < n; ++i) {
            string c; int k;
            cin >> c >> k;

            if (c == "cat")
                ct.insert(new cat(k));
            else{
                cin >> d;
                ct.insert(new drug_cat(k, d));
                }
        }
        for_each(ct.begin(), ct.end(), Print);
        cout << "---" << endl;
    }
    return 0;
}
