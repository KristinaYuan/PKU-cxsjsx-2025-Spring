#include <iostream>
#include <map>
#include <set>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, set<int>> members;
    members[1000000000].insert(1); // facer
    
    for (int t = 0; t < n; t++) {
        int id, power;
        cin >> id >> power;
        
        auto it = members.lower_bound(power);
        int min_diff = INT_MAX;
        int opponent_id = INT_MAX;
        
        // 1. 检查是否存在相同power
        if (it != members.end() && it->first == power) {
            opponent_id = *(it->second.begin()); // 取最小id
        } 
        else {
            // 2. 检查后继（≥power的最小值）
            if (it != members.end()) {
                int diff = it->first - power;
                if (diff < min_diff) {
                    min_diff = diff;
                    opponent_id = *(it->second.begin());
                } else if (diff == min_diff) {
                    opponent_id = min(opponent_id, *(it->second.begin()));
                }
            }
            
            // 3. 检查前驱（<power的最大值）
            if (it != members.begin()) {
                auto prev_it = prev(it);
                int diff = power - prev_it->first;
                if (diff < min_diff) {
                    min_diff = diff;
                    opponent_id = *(prev_it->second.begin());
                } else if (diff == min_diff) {
                    opponent_id = min(opponent_id, *(prev_it->second.begin()));
                }
            }
        }
        
        cout << id << " " << opponent_id << endl;
        members[power].insert(id); // 插入新会员
    }
    
    return 0;
}
