#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int n = special.size();
        int res = special[0] - bottom;
        for (int i = 1; i < n; i++) {
            res = max(res, special[i] - special[i - 1] - 1);
        }
        res = max(res, top - special[n - 1]);
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

