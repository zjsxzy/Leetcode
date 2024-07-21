#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        for (auto c: s) {
            if (check(c)) cnt++;
        }
        if (cnt == 0) return false;
        if (cnt & 1) return true;
        return true;
    }

    bool check(char c) {
        return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
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

