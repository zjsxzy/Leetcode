#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<int> vst(n, 1);
        for (int i = 2; i < n; i++) {
            if (vst[i]) {
                for (int j = i + i; j < n; j += i) {
                    vst[j] = 0;
                }
            }
        }
        vector<vector<int>> ans;
        for (int i = 2; i <= n / 2; i++) {
            if (vst[i] && vst[n - i]) {
                ans.push_back({i, n - i});
            }
        }
        return ans;
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

