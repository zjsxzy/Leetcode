#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto q: queries) {
            int t = calc(q[0], q[1]);
            ans.push_back(t);
        }
        return ans;
    }

    int calc(int a, int b) {
        if (a > b) swap(a, b);
        int la = level(a), lb = level(b);
        for (int i = 0; i < lb - la; i++) {
            b >>= 1;
        }
        while (a != b) {
            a >>= 1;
            b >>= 1;
        }
        int lp = level(a);
        return la + lb - 2 * lp + 1;
    }

    int level(int x) {
        for (int i = 31; i >= 0; i--) {
            if (x >> i & 1) return i + 1;
        }
        return 0;
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

