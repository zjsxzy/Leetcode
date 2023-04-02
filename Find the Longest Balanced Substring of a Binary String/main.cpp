#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.size(), res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (check(s.substr(i, j - i + 1))) {
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }

    bool check(string s) {
        int n = s.size();
        if (n == 0) return true;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == '1' && s[j] == '0') return false;
            }
        }
        int c0 = 0, c1 = 0;
        for (auto c: s) {
            if (c == '0') c0++;
            else c1++;
        }
        return c0 == c1;
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

