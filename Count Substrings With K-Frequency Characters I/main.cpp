#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        vector cnt(n + 1, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                cnt[i + 1][j] = cnt[i][j] + (s[i] - 'a' == j);
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                bool flag = false;
                for (int c = 0; c < 26; c++) {
                    if (cnt[j][c] - cnt[i - 1][c] >= k) {
                        flag = true;
                        break;
                    }
                }
                // cout << i << ' ' << j << ' ' << flag << endl;
                if (flag) {
                    res += n - j + 1;
                    break;
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

