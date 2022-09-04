#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for (int b = 2; b <= n - 2; b++) {
            if (!check(n, b)) return false;
        }
        return true;
    }

    bool check(int n, int b) {
        string s;
        while (n) {
            s += to_string(n % b);
            n /= b;
        }
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
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

