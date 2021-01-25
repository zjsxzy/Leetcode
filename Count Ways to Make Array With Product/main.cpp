#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 10000;
const int MAXK = 15;
const int MOD = 1e9 + 7;
long long comb[MAXN + MAXK + 1][MAXK + 1];
class Solution {
public:

    void init() {
        memset(comb, 0, sizeof(comb));
        for (int i = 0; i < MAXN + MAXK; i++) {
            comb[i][0] = 1;
        }
        for (int i = 1; i < MAXN + MAXK; i++) {
            for (int j = 1; j <= i && j < MAXK; j++) {
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
                comb[i][j] %= MOD;
            }
        }
    }

    int calc(int n, int k) {
        long long res = 1;
        for (int p = 2; p * p <= k; p++) {
            if (k % p == 0) {
                int cnt = 0;
                while (k % p == 0) {
                    k /= p;
                    cnt++;
                }
                res = res * comb[n + cnt - 1][cnt] % MOD;
            }
        }
        if (k != 1) {
            res = res * (long long)n % MOD;
        }
        return (int)res;
    }

    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        init();
        vector<int> res;
        for (auto &x : queries) {
            int t = calc(x[0], x[1]);
            res.push_back(t);
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
    solve();
    return 0;
}

