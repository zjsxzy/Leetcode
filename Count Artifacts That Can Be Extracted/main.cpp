#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 1005;
int vst[maxn][maxn];
class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vst[i][j] = 0;
            }
        }
        for (auto& d: dig) {
            vst[d[0]][d[1]] = 1;
        }
        int res = 0;
        for (auto& a: artifacts) {
            bool flag = true;
            for (int x = a[0]; x <= a[2] && flag; x++) {
                for (int y = a[1]; y <= a[3] && flag; y++) {
                    if (!vst[x][y]) {
                        flag = false;
                    }
                }
            }
            if (flag) res++;
        }
        return res;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

