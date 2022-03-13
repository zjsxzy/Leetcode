#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

#define abs(x) ((x) > 0 ? (x) : -(x))
class Solution {
public:
    int dist(string s, string t) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) res++;
        }
        return res;
    }
    int minSwaps(string s) {
        int n = s.size();
        vector<int> sum(2);
        for (auto &c : s) {
            sum[c - '0']++;
        }
        if (n % 2 == 0) {
            if (sum[0] != sum[1]) {
                return -1;
            }
            string t = "";
            for (int i = 0; i < n; i++) {
                if (i & 1) t += '0';
                else t += '1';
            }
            int d1 = dist(s, t);
            t = "";
            for (int i = 0; i < n; i++) {
                if (i & 1) t += '1';
                else t += '0';
            }
            int d2 = dist(s, t);
            // cout << d1 << " " << d2 << endl;
            return min(d1, d2) / 2;
        } else {
            if (abs(sum[0] - sum[1]) != 1) {
                return -1;
            }
            if (sum[0] > sum[1]) {
                string t = "";
                for (int i = 0; i < n; i++) {
                    if (i & 1) t += '1';
                    else t += '0';
                }
                int d = dist(s, t);
                return d / 2;
            } else {
                string t = "";
                for (int i = 0; i < n; i++) {
                    if (i & 1) t += '0';
                    else t += '1';
                }
                int d = dist(s, t);
                return d / 2;
            }
        }
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

