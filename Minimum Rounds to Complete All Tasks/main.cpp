#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        map<int, int> cnt;
        for (auto t: tasks) cnt[t]++;
        int res = 0;
        for (auto& [k, v]: cnt) {
            int t = calc(v);
            if (t == -1) return -1;
            res += t;
        }
        return res;
    }
    int calc(int a) {
        // a = 2 * x + 3 * y;
        int res = INT_MAX;
        for (int y = 0; y * 3 <= a; y++) {
            if ((a - y * 3) % 2 == 0) {
                res = min(res, y + (a - y * 3) / 2);
            }
        }
        if (res == INT_MAX) return -1;
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

