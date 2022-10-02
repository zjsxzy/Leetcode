#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int deleteString(string s) {
        int n = s.size();
        vector<vector<int>> lcp(n + 1, vector<int>(n + 1));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
            }
        }
        vector<int> f(n);
        for (int i = n - 1; i >= 0; i--) {
            f[i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] >= j - i) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        return f[0];
    }
};

int main() {
#ifndef ONLINE_JUDGE
   (void)!freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

