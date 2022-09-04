#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<vector<int>> d(26);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            d[s[i] - 'a'].push_back(i);
        }
        for (int i = 0; i < 26; i++) {
            if (d[i].size() == 0) continue;
            if (d[i].size() != 2) return false;
            if (d[i][1] - d[i][0] != distance[i] + 1) return false;
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

