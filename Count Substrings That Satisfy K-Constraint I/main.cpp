#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size(), res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (check(s.substr(i, j - i + 1), k)) {
                    res++;
                }
            }
        }
        return res;
    }

    bool check(string s, int k) {
        int c0 = 0, c1 = 0;
        for (auto c: s) {
            if (c == '0') c0++;
            else c1++;
        }
        return (c0 <= k) || (c1 <= k);
    }
};

void solve() {
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
       solve();
    }
    return 0;
}

