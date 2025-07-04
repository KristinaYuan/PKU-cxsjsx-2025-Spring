#include <iostream>
using namespace std;

class Matrix {
private:
    int **data;
public:
    Matrix(int n, int m) {
        data = new int*[n];
        for (int i=0; i<n; i++) {
            data[i] = new int[m];
            for (int j = 0; j < m; j++)
                cin >> data[i][j];
        }
    }

    operator int* (){
        return *data;
    }
    int* operator[] (int i) {
        return data[i];
    }
};

int main() {
    int t;
    cin >> t;
    Matrix m(3, 3);
    cout << m[1][2] << endl;    
    m[0][1] = t;
    cout << m[0][1] << endl;    
    return 0;
}
