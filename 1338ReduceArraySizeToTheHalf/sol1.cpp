#include <algorithm>
#include <unordered_map>

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> count;
        for(int x: arr) {
            if(count.find(x) != count.end()) {
                count[x]++;
            } else {
                count[x] = 1;
            }
        }
       vector<int> ordered_count;
        for(auto p: count) {
            ordered_count.push_back(p.second);
        }
        sort(ordered_count.begin(), ordered_count.end());
        int num = 0, mini_size = 0;
        for(auto itr = ordered_count.rbegin(); itr != ordered_count.rend(); itr++) {
            num += *itr;
            mini_size++;
            if(num*2 >= arr.size()) break;
        }
        return mini_size;
    }
};