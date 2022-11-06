#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        int n = transactions.size();
        long long total_loss = 0;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            total_loss += max(transactions[i][0] - transactions[i][1], 0);
            mx = max(mx, min(transactions[i][0], transactions[i][1]));
        }
        return total_loss + mx;
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

