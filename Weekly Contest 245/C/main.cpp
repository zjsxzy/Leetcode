#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> res(3);
        for (auto &v : triplets) {
            if (v[0] <= target[0] && v[1] <= target[1] && v[2] <= target[2]) {
                res[0] = max(res[0], v[0]);
                res[1] = max(res[1], v[1]);
                res[2] = max(res[2], v[2]);
            }
        }
        return res == target;
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

