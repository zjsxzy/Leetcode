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
typedef long long LL;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n), g(n);
        f[0] = 1;
        for (int i = 1; i < n; i++) {
            f[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && f[j] + 1 > f[i]) {
                    f[i] = f[j] + 1;
                }
            }
        }
        g[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            g[i] = 1;
            for (int j = n - 1; j > i; j--) {
                if (nums[i] > nums[j] && g[j] + 1 > g[i]) {
                    g[i] = g[j] + 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (f[i] > 1 && g[i] > 1) {
                res = max(res, f[i] + g[i] - 1);
            }
        }
        return n - res;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    return 0;
}

