#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int num = 0;
        int n = s.size(), q = queries.size();
        map<int, int> pos, len;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < 31; j++) {
                string sub = s.substr(i, j);
                if (sub[0] == '0' && sub.size() > 1) continue;
                reverse(sub.begin(), sub.end());
                int num = 0;
                for (int k = 0; k < sub.size(); k++) {
                    if (sub[k] == '1') num |= (1 << k);
                }
                if (pos.find(num) == pos.end()) {
                    pos[num] = i;
                    len[num] = sub.size();
                }
            }
        }
        vector<vector<int>> ans;
        for (auto que: queries) {
            int v = que[0] ^ que[1];
            if (pos.find(v) == pos.end()) ans.push_back({-1, -1});
            else {
                ans.push_back({pos[v], pos[v] + len[v] - 1});
            }
        }

        return ans;
    }

};

void solve() {
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

