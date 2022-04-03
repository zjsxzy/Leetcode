#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 1000005;
int win[maxn], lose[maxn], use[maxn];
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = 100000;
        for (int i = 1; i <= n; i++) {
            win[i] = 0;
            lose[i] = 0;
            use[i] = 0;
        }
        for (auto& m: matches) {
            win[m[0]]++;
            lose[m[1]]++;
            use[m[0]] = 1; use[m[1]] = 1;
        }
        vector<vector<int>> res;
        vector<int> v1, v2;
        for (int i = 1; i <= n; i++) {
            if (use[i] == 1) {
                if (lose[i] == 0) v1.push_back(i);
                else if (lose[i] == 1) v2.push_back(i);
            }
        }
        res.push_back(v1);
        res.push_back(v2);
        return res;
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

