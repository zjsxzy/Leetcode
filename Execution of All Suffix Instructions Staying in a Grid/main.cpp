#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> res;
        int m = s.size();
        for (int i = 0; i < m; i++) {
            int t = search(n, startPos, s, i);
            res.push_back(t);
        }
        return res;
    }

    int search(int n, vector<int>& startPos, string& s, int st) {
        int x = startPos[0], y = startPos[1], tot = 0;
        int m = s.size();
        // cout << st << endl;
        for (int i = st; i < m; i++) {
            if (s[i] == 'R') {
                y++;
            } else if (s[i] == 'L') {
                y--;
            } else if (s[i] == 'D') {
                x++;
            } else {
                x--;
            }
            // cout << s[i] << " " << x << " " << y << " " << tot << endl;
            if (inside(x, y, n)) {
                tot++;
            } else {
                return tot;
            }

        }
        return tot;
    }

    bool inside(int x, int y, int n) {
        return (x >= 0) && (x < n) && (y >= 0) && (y < n);
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

