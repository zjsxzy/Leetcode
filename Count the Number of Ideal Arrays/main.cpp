#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    const int mod = 1e9 + 7;
    const int maxp = 16;
    int idealArrays(int n, int maxValue) {
        // 计算质因子
        vector<vector<int>> fac(maxValue + 1);
        for (int i = 1; i <= maxValue; i++) {
            for (int j = i * 2; j <= maxValue; j += i) {
                fac[j].push_back(i);
            }
        }

        vector<vector<long long>> f(maxValue + 1, vector<long long>(maxp + 1));
        for (int i = 1; i <= maxValue; i++) {
            f[i][1] = 1;
            for (int j = 2; j <= maxp; j++) {
                for (auto p: fac[i]) {
                    f[i][j] = (f[i][j] + f[p][j - 1]) % mod;
                }
            }
        }


        vector<vector<long long>> comb(n + 1, vector<long long>(maxp + 1));
        for (int i = 0; i <= n; i++) {
            comb[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i && j <= maxp; j++) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
            }
        }

        long long res = 0;
        for (int i = 1; i <= maxValue; i++) {
            for (int j = 1; j <= maxp; j++) {
                res = (res + comb[n - 1][j - 1] * f[i][j]) % mod;
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

