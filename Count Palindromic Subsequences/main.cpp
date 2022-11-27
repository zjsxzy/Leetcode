#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;
int suff[10], suff2[10][10], pref[10], pref2[10][10];
class Solution {
public:
    int countPalindromes(string s) {
        int n = s.size();
        memset(suff, 0, sizeof(suff));
        memset(suff2, 0, sizeof(suff2));
        for (int i = n - 1; i >= 0; i--) {
            int d = s[i] - '0';
            for (int j = 0; j < 10; j++) {
                suff2[d][j] += suff[j];
            }
            suff[d]++;
        }
        memset(pref, 0, sizeof(pref));
        memset(pref2, 0, sizeof(pref2));
        long long res = 0;
        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';

            suff[d]--;
            for (int j = 0; j < 10; j++) {
                suff2[d][j] -= suff[j];
            }

            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    res += (long long)pref2[k][j] * suff2[j][k];
                    res %= mod;
                }
            }

            for (int j = 0; j < 10; j++) {
                pref2[j][d] += pref[j];
            }
            pref[d]++;
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

