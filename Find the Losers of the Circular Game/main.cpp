#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> vst(n);
        int s = 0, i = 1;
        while (!vst[s]) {
            vst[s] = 1;
            s = (s + i * k) % n;
            i++;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) if (!vst[i]) ans.push_back(i + 1);
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

