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
#include <cassert>
#include <climits>
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
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<bool> res;
        for (int i = 0; i < m; i++) {
            vector<int> vec;
            for (int j = l[i]; j <= r[i]; j++) {
                vec.push_back(nums[j]);
            }
            int k = vec.size();
            if (k == 1) {
                res.push_back(true);
                continue;
            }
            sort(vec.begin(), vec.end());
            int diff = vec[1] - vec[0];
            bool flag = true;
            for (int j = 1; j < k; j++) {
                if (vec[j] - vec[j - 1] != diff) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};

int main() {
}

