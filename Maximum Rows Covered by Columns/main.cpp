#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int n = mat.size(), m = mat[0].size();
        int res = 0;
        for (int s = 0; s < (1 << m); s++) {
            int b = 0;
            for (int j = 0; j < m; j++) {
                if (s >> j & 1) b++;
            }
            if (b != cols) continue;
            int t = 0;
            for (int i = 0; i < n; i++) {
                bool flag = true;
                for (int j = 0; j < m; j++) {
                    if (mat[i][j] == 1 && !(s >> j & 1)) flag = false;
                }
                if (flag) t++;
            }
            res = max(res, t);
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

