#include<iostream>
#include<vector>
using namespace std;
class B{
public:
    int val;
    static int product;
    B(int x) {
        product *= x;
        val = product;
    }
    void output() {
        cout << val << endl;
    }
};
int B::product = 1; 
int main(){
  int n; cin >> n;
  vector<B*> p;
  for(int i = 0; i < n; i++){
    int x; cin >> x;
    p.push_back(new B(x));
  }
  for(int i = 0; i < n; ++i)
    p[i]->output();
  return 0;
}
