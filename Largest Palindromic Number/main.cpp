#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    string largestPalindromic(string num) {
        int n = num.size();
        vector<int> cnt(10);
        for (auto c: num) cnt[c - '0']++;
        string res;
        bool flag = false;
        for (int i = 9; i > 0; i--) {
            if (cnt[i] > 1) {
                // cout << i << endl;
                for (int j = 0; j < cnt[i] / 2; j++) {
                    res += (char)('0' + i);
                }
                cnt[i] -= (cnt[i] / 2) * 2;
                flag = true;
            }
        }
        if (!flag) {
            for (int i = 9; i >= 0; i--) {
                if (cnt[i]) {
                    res += (char)('0' + i);
                    return res;
                }
            }
        }
        if (cnt[0] > 1) {
            for (int j = 0; j < cnt[0] / 2; j++) {
                res += '0';
            }
            cnt[0] -= (cnt[0] / 2) * 2;
        }
        string t = res;
        reverse(t.begin(), t.end());
        for (int i = 9; i >= 0; i--) {
            if (cnt[i]) {
                res += (char)('0' + i);
                return res + t;
            }
        }
        return res + t;
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

