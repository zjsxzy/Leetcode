#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        int n = message.size();
        for (int i = 1, cap = 0, tail_len; ; i++) {
            if (i < 10) tail_len = 5;
            else if (i < 100) {
                if (i == 10) cap -= 9;
                tail_len = 7;
            } else if (i < 1000) {
                if (i == 100) cap -= 99;
                tail_len = 9;
            } else {
                if (i == 1000) cap -= 999;
                tail_len = 11;
            }
            if (tail_len >= limit) return {};
            cap += limit - tail_len;
            // cout << i << ' ' << cap << endl;
            if (cap < n) continue;

            vector<string> ans(i);
            for (int j = 0, k = 0; j < i; j++) {
                string tail = "<" + to_string(j + 1) + "/" + to_string(i) + ">";
                if (j == i - 1) ans[j] = message.substr(k) + tail;
                else {
                    int m = limit - tail.size();
                    ans[j] = message.substr(k, m) + tail;
                    k += m;
                }
            }
            return ans;
        }
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

