#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        reverse(queries.begin(), queries.end());
        set<int> row, col;
        for (int i = 0; i < n; i++) {
            row.insert(i);
            col.insert(i);
        }
        long long res = 0;
        for (auto q: queries) {
            if (q[0] == 0) {
                if (row.count(q[1])) {
                    res += (long long)col.size() * q[2];
                    row.erase(q[1]);
                }
            } else {
                if (col.count(q[1])) {
                    res += (long long)row.size() * q[2];
                    col.erase(q[1]);
                }
            }
        }
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

