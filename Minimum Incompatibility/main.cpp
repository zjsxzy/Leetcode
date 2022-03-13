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

const int INF = 10000;
class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> cnt;
        for (auto x : nums) {
            cnt[x]++;
        }
        for (auto x : cnt) {
            if (x.second > k) return -1;
        }
        sort(nums.begin(), nums.end());
        if (k == 1) return nums.back() - nums[0];
        if (k == n) return 0;

        vector<int> diff(1 << n, 0);
        vector<int> a;
        for (int s = 1; s < (1 << n); s++) {
            a.clear();
            for (int i = 0; i < n; i++) {
                if ((s >> i) & 1) {
                    a.push_back(nums[i]);
                }
            }
            if (a.size() != n / k) {
                diff[s] = INF;
                continue;
            }
            sort(a.begin(), a.end());
            bool flag = true;
            for (int i = 0; i < a.size() - 1; i++) {
                if (a[i] == a[i + 1]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                diff[s] = a.back() - a[0];
            } else {
                diff[s] = INF;
            }
        }

        vector<int> dp(1 << n, INF);
        dp[0] = 0;
        for (int s = 1; s < (1 << n); s++) {
            for (int t = s; t > 0; t = (t - 1) & s) {
                if (__builtin_popcount(t) == n / k) {
                    dp[s] = min(dp[s], dp[s ^ t] + diff[t]);
                }
            }
        }
        int res = dp[(1 << n) - 1];
        if (res == INF) res = -1;
        return res;
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

