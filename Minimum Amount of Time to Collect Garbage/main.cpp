#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int res = calc(garbage, travel, 'M');
        res += calc(garbage, travel, 'P');
        res += calc(garbage, travel, 'G');
        return res;
    }

    int calc(vector<string>& g, vector<int>& t, char c) {
        int n = g.size(), p = -1, cnt = 0;
        for (int i = 0; i < n; i++) {
            int curr = 0;
            for (int j = 0; j < g[i].size(); j++) {
                curr += (g[i][j] == c);
            }
            if (curr > 0) {
                cnt += curr;
                p = i;
            }
        }
        if (p == -1) return 0;
        int res = 0;
        for (int i = 0; i < p; i++) res += t[i];
        return res + cnt;
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

