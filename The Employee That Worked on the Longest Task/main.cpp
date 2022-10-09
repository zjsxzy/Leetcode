#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int curr = 0, mx = 0, res = n + 1;
        for (auto l: logs) {
            if (l[1] - curr > mx || (l[1] - curr == mx && l[0] < res)) {
                mx = l[1] - curr;
                res = l[0];
            }
            curr = l[1];
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

