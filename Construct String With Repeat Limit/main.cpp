#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<int, int>> q;
        vector<int> cnt(26);
        for (auto c: s) {
            cnt[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] != 0) {
                // cout << char('a' + i) << " " << cnt[i] << endl;
                q.push({i, cnt[i]});
            }
        }
        cout << endl;
        int curr = 0, prev = -1;
        string res;
        while (!q.empty()) {
            auto t = q.top(); q.pop();

            if (curr == repeatLimit && prev == t.first) {
                if (q.empty()) return res;
                auto tt = q.top(); q.pop();
                // cout << char('a' + tt.first) << " " << tt.second << " " << curr << endl;
                res += 'a' + tt.first;
                if (tt.first == prev) curr++;
                else curr = 1;
                tt.second--;
                prev = tt.first;
                if (tt.second > 0) q.push(tt);
                q.push(t);
            } else {
                // cout << char('a' + t.first) << " " << t.second << " " << curr << endl;
                res += 'a' + t.first;
                if (t.first == prev) curr++;
                else curr = 1;
                t.second--;
                prev = t.first;
                if (t.second > 0) q.push(t);
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
    solve();
    return 0;
}

