#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size(), m = t.size(), i = 0, j = 0;
        for (i = 0; i < n; i++) {
            if (s[i] == t[j]) {
                j++;
                if (j == m) break;
            }
        }
        return m - j;
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

