#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        vector<int> t(n);
        for (int i = 0; i < n; i++) {
            t[i] = (health[i] - 1) / power + 1;
        }
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j){
            return 1ll * t[i] * damage[j] < 1ll * t[j] * damage[i];
        });
        long long res = 0, tim = 0;
        for (auto i: ord) {
            tim += t[i];
            res += 1ll * damage[i] * tim;
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

