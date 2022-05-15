#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        vector<int> bits(30);
        for (int i = 0; i < 30; i++) {
            for (auto x: candidates) {
                if (x >> i & 1) bits[i]++;
            }
        }
        int res = 0;
        for (int i = 0; i < 30; i++) res = max(res, bits[i]);
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

