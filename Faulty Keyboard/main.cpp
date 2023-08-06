#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    string finalString(string s) {
        string res;
        for (auto c: s) {
            if (c == 'i') reverse(res.begin(), res.end());
            else res += c;
        }
        return res;
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

