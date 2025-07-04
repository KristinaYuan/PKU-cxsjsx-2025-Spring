#include <iostream>
#include <string>
using namespace std;

template <class T>
void print(T a) {
    cout << a << endl;
}

class MyString {
public:
    string m_data;
    MyString(string a) : m_data(a) {}
    MyString operator+ (const MyString& other) {
        return MyString(m_data + other.m_data);
    }
    friend ostream& operator<< (ostream& os, MyString& obj) {
        os << obj.m_data;
        return os;
    }
};

template <class T>
class MyTemplateClass {
public:
    T val;
    MyTemplateClass(T v):val(v){}
    operator T() {
        return val;
    }
    friend ostream& operator<< (ostream& os, MyTemplateClass& obj) {
        auto tmp = obj.val + obj.val;
        os << tmp;
        return os;
    }
};

int main()
{
    int m;
    int num;
    string str;
    cin >> m;
    for (; m > 0; m--) {
        cin >> num >> str;
        MyTemplateClass<int> obj(num);
        print(int(obj));
        print(obj);
        MyTemplateClass<MyString> obj2(str);
        print(MyString(obj2));
        print(obj2);
    }
}
