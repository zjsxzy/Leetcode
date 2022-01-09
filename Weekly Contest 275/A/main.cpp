#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            vector<int> vis(n + 1);
            for (int j = 0; j < n; j++) {
                vis[matrix[i][j]] = 1;
            }
            for (int x = 1; x <= n; x++) {
                if (!vis[x]) return false;
            }
        }
        for (int j = 0; j < n; j++) {
            vector<int> vis(n + 1);
            for (int i = 0; i < n; i++) {
                vis[matrix[i][j]] = 1;
            }
            for (int x = 1; x <= n; x++) {
                if (!vis[x]) return false;
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
    solve();
    return 0;
}

