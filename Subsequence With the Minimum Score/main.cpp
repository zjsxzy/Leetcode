#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int minimumScore(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> pre(m, n), suf(m, -1);
        for (int i = 0, j = 0; i < m; i++) {
            while (j < n && s[j] != t[i]) j++;
            if (j < n) {
                pre[i] = j;
                j++;
            }
        }
        for (int i = m - 1, j = n - 1; i >= 0; i--) {
            while (j >= 0 && s[j] != t[i]) j--;
            if (j >= 0) {
                suf[i] = j;
                j--;
            }
        }
        int res = m;
        for (int i = 0; i < m; i++) {
            if (pre[i] < n) res = min(res, m - i - 1);
        }
        for (int i = m - 1; i >= 0; i--) {
            if (suf[i] < 0) break;
            int j = lower_bound(pre.begin(), pre.end(), suf[i]) - pre.begin();
            j = min(j, i);
            res = min(res, i - j);
        }
        return res;
    }
};

void solve() {
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

