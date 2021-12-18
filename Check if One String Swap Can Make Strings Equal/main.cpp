#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    bool areAlmostEqual(string s, string t) {
        int n = s.size();
        if (s == t) return true;
        string s_diff, t_diff;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                s_diff += s[i];
                t_diff += t[i];
                if (s_diff.size() > 2) return false;
            }
        }
        reverse(t_diff.begin(), t_diff.end());
        // cout << s << " " << t << endl;
        return (s_diff.size() == 2) && (s_diff == t_diff);
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

