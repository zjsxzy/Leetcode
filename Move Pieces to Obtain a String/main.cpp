#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        vector<pair<char, int>> vs, vt;
        for (int i = 0; i < n; i++) {
            if (start[i] != '_') vs.push_back({start[i], i});
            if (target[i] != '_') vt.push_back({target[i], i});
        }
        if (vs.size() != vt.size()) return false;
        int m = vs.size();
        for (int i = 0; i < m; i++) {
            if (vs[i].first != vt[i].first) return false;
            if (vs[i].first == 'L' && vs[i].second < vt[i].second) return false;
            if (vs[i].first == 'R' && vs[i].second > vt[i].second) return false;
        }
        return true;
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

