#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int r = 0, n = s.size(), sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                if (sum >= k || (n - 1 - i) > 30) r++;
                else {
                    sum += (1ll << (n - 1 - i));
                    if (sum > k) r++;
                }
            }
        }
        return n - r;
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

