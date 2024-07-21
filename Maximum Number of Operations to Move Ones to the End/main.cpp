#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int maxOperations(string s) {
        int n = s.size(), res = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') cnt++;
            else {
                if (i > 0 && s[i - 1] == '1') res += cnt;
            }
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

