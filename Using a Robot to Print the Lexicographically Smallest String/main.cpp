#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> mn(n);
        mn[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            mn[i] = min(mn[i + 1], s[i]);
            // cout << i << ' ' << mn[i] << endl;
        }
        vector<char> t;
        string res;
        for (int i = 0; i < n; i++) {
            while (t.size() > 0 && t.back() <= mn[i]) {
                res += t.back();
                t.pop_back();
            }
            t.push_back(s[i]);
        }
        while (t.size() > 0) {
            res += t.back();
            t.pop_back();
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

