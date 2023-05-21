#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            s[i] = min(s[i], s[n - i - 1]);
            s[n - i - 1] = s[i];
        }
        return s;
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

