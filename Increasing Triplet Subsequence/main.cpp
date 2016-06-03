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
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<bool> f(n), g(n);
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            mn = min(mn, nums[i]);
            f[i] = nums[i] > mn ? true : false;
        }
        int mx = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            mx = max(mx, nums[i]);
            g[i] = nums[i] < mx ? true : false;
        }
        for (int i = 0; i < n; i++) {
            if (f[i] && g[i]) return true;
        }
        return false;
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	return 0;
}

