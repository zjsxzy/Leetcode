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
    int getMaximumGenerated(int n) {
        vector<int> nums(n+1);
        nums[0] = 0;
        if (n == 0) return 0;
        nums[1] = 1;
        if (n == 1) return 1;
        for (int i = 1; i <= n; i++) {
            if (2 * i <= n)
                nums[2 * i] = nums[i];
            if (2 * i + 1 <= n)
                nums[2 * i + 1] = nums[i] + nums[i + 1];
        }
        int mx = 0;
        for (int i = 0; i <= n; i++) {
            if (nums[i] > mx) mx = nums[i];
        }
        return mx;
    }
};

int main() {
    Solution sol;
    cout << sol.getMaximumGenerated(100) << endl;
}

