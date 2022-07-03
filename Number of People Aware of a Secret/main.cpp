#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> f(n + 1);
        f[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (i >= j + delay && i < j + forget) {
                    f[i] += f[j];
                    f[i] %= mod;
                }
            }
            // cout << i << ' ' << f[i] << endl;
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (i + forget > n) {
                res += f[i];
                res %= mod;
            }
        }
        return res;
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

