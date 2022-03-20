#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int n = 12;
        int score = 0, state = 0;
        for (int i = 0; i < (1 << n); i++) {
            int s = 0, arrows = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    s += j;
                    arrows += aliceArrows[j] + 1;
                }
            }
            if (arrows <= numArrows && s > score) {
                score = max(score, s);
                state = i;
            }
        }
        // cout << score << endl;
        vector<int> bob(n);
        int arrows = numArrows;
        for (int j = 0; j < n; j++) {
            if (state & (1 << j)) {
                // cout << j << " " << aliceArrows[j] + 1 << endl;
                bob[j] = aliceArrows[j] + 1;
                arrows -= (aliceArrows[j] + 1);
            }
        }
        // cout << arrows << endl;
        for (int j = 0; j < n; j++) {
            if (!bob[j] && aliceArrows[j]) {
                // cout << j << " " << arrows << " " << aliceArrows[j] << endl;
                int t = min(aliceArrows[j], arrows);
                bob[j] = t;
                arrows -= t;
            }
        }
        return bob;
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

