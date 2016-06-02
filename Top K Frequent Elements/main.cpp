#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> hs;
        for (int i = 0; i < n; i++) {
            if (hs.find(nums[i]) == hs.end()) {
                hs.insert(pair<int, int>(nums[i], 1));
            } else {
                hs[nums[i]]++;
            }
        }
        vector<pair<int, int> > vec;
        for (map<int, int>::iterator it = hs.begin(); it != hs.end(); it++) {
            vec.push_back(pair<int, int>(-(it->second), it->first));
        }
        sort(vec.begin(), vec.end());
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(vec[i].second);
        }
        return res;
    }
};
int main() {
    int x[] = {1,1,1,2,2,3};
    vector<int> nums(x, x + sizeof(x) / sizeof(int));
    Solution sol;
    sol.topKFrequent(nums, 2);
    return 0;
}

