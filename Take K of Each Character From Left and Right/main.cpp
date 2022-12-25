#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        s += s;
        int i = 0, j = 0, res = INT_MAX;
        vector<int> cnt(3);
        while (i < n) {
            while (j < 2 * n && j - i < n && !ok(cnt, k)) {
                cnt[s[j] - 'a']++;
                j++;
            }
            if (ok(cnt, k) && (j >= n || i == 0)) {
                res = min(res, j - i);
            }
            cnt[s[i] - 'a']--;
            i++;
        }
        if (res == INT_MAX) res = -1;
        return res;
    }
    bool ok(vector<int>& cnt, int k) {
        return cnt[0] >= k && cnt[1] >= k && cnt[2] >= k;
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

