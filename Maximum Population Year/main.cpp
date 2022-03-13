#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int, int> cnt;
        for (int x = 1950; x <= 2050; x++) {
            for (auto &v : logs) {
                if (v[0] <= x && x < v[1]) {
                    cnt[x]++;
                }
            }
        }
        int mx = 0, year = -1;
        for (auto &[k, v] : cnt) {
            if (v > mx) {
                mx = v;
                year = k;
            }
        }
        return year;
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

