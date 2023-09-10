#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> vst(105);
        for (auto v: nums) {
            for (int i = v[0]; i <= v[1]; i++) vst[i] = 1;
        }
        int res = 0;
        for (int i = 1; i <= 100; i++) res += vst[i];
        return res;
    }
};

void solve() {
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
       solve();
    }
    return 0;
}

