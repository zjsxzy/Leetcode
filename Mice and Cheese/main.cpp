#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        int res = 0, t = 0;
        vector<int> pos, neg;
        for (int i = 0; i < n; i++) {
            int a = reward1[i], b = reward2[i];
            if (a < b) {
                res += b;
                neg.push_back(a - b);
            } else {
                res += a;
                t++;
                pos.push_back(a - b);
            }
        }
        sort(pos.begin(), pos.end());
        sort(neg.rbegin(), neg.rend());
        if (t == k) return res;
        if (t < k) {
            for (int i = 0; i < k - t; i++) {
                res += neg[i];
            }
        } else {
            for (int i = 0; i < t - k; i++) {
                res -= pos[i];
            }
        }
        return res;
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

