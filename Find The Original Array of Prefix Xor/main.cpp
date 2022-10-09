#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res;
        res.push_back(pref[0]);
        int n = pref.size();
        for (int i = 1; i < n; i++) {
            res.push_back(pref[i - 1] ^ pref[i]);
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

