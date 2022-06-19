#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int minimumNumbers(int num, int k) {
        vector<int> a;
        for (int i = k; i <= num; i += 10) {
            a.push_back(i);
        }
        int n = a.size();
        // for (auto x: a) cout << x << ' ';
        // cout << endl;
        vector<int> dp(num + 1, 1e9);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= num; j++) {
                if (j - a[i] >= 0 && dp[j - a[i]] != 1e9) {
                    dp[j] = min(dp[j], dp[j - a[i]] + 1);
                }
            }
        }
        if (dp[num] == 1e9) return -1;
        return dp[num];
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

