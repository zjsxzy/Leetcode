#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int cnt = 0;
        for (auto c: s) {
            if (c == letter) cnt++;
        }
        return 100 * cnt / s.size();
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

