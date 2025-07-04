#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {

    int n;  // 每组的人数
    cin >> n;
    
    vector<Person> people;
    for (int i = 0; i < n; ++i) {
        string name;
        int age;
        cin >> name >> age;
        people.push_back({name, age});
    }
    
    sort(people.begin(), people.end(),
[](struct Person& a, struct Person& b) {
            return a.age > b.age;
        }
);
    
    for (const auto& p : people) {
        cout << p.name << "(" << p.age << ") ";
    }
    cout << endl;
    
    return 0;
}
