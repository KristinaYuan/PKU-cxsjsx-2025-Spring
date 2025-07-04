#include <iostream>
using namespace std;

template <class T1, class T2, class T3>
auto combine(T1 func1, T2 func2) {
    return [func1, func2](T3 x) {
        return func1(func1(x) + func2(x));
        };
}

int main()
{
    auto Square = [](double a) { return a * a; };
    auto Inc = [](double a) { return a + 1; };
    cout << combine<decltype(Square), decltype(Inc), int>(Square, Inc)(3) << endl;
    cout << combine<decltype(Inc), decltype(Square), double>(Inc, Square)(2.5) << endl;

    return 0;
}
