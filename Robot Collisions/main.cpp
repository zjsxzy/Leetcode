#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pair<pair<int, int>, pair<int, char>>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({{positions[i], healths[i]}, {i, directions[i]}});
        }
        sort(v.begin(), v.end());
        vector<pair<int, int>> stk, left;
        for (int i = 0; i < n; i++) {
            int h = v[i].first.second;
            int idx = v[i].second.first;
            char d = v[i].second.second;

            if (d == 'R') {
                stk.push_back({idx, h});
                continue;
            }
            while (h > 0 && !stk.empty()) {
                auto p = stk.back(); stk.pop_back();
                if (h == p.second) {
                    h = 0;
                } else if (h > p.second) {
                    h--;
                } else if (h < p.second) {
                    h = 0;
                    if (p.second - 1 > 0) stk.push_back({p.first, p.second - 1});
                }
            }
            if (h > 0 && stk.empty()) {
                left.push_back({idx, h});
            }
        }
        for (auto x: stk) left.push_back(x);
        sort(left.begin(), left.end());
        vector<int> ans;
        for (auto p: left) ans.push_back(p.second);
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

