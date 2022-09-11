#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int partitionString(string s) {
        int n = s.size(), res = 1;
        vector<int> cnt(26);
        for (int i = 0; i < n; i++) {
            int t = s[i] - 'a';
            if (cnt[t] != 0) {
                for (int j = 0; j < 26; j++) cnt[j] = 0;
                res++;
            }
            cnt[t]++;
        }
        return res;
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

