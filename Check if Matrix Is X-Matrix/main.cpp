#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || i == n - j - 1) {
                    // cout << grid[i][j] << endl;
                    if (grid[i][j] == 0) return false;
                } else {
                    // cout << grid[i][j] << endl;
                    if (grid[i][j] != 0) return false;
                }
            }
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

