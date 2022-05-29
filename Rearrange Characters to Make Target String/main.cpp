#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map<char, int> cnt;
        for (auto c: s) cnt[c]++;
        map<char, int> mp;
        for (auto c: target) {
            if (cnt.find(c) == cnt.end()) return 0;
            mp[c]++;
        }
        int res = INT_MAX;
        for (auto [k, v]: mp) {
            res = min(res, cnt[k] / v);
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
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

