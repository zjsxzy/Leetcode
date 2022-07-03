#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char, int> mp;
        int n = key.size(), tot = 0;
        for (int i = 0; i < n; i++) {
            if (key[i] >= 'a' && key[i] <= 'z' && mp.find(key[i]) == mp.end()) {
                mp[key[i]] = tot++;
                // cout << key[i] << ' ' <<(char)('a' + tot) << endl;
            }
        }
        string res;
        for (auto c: message) {
            if (c >= 'a' && c <= 'z') {
                res += (char)('a' + mp[c]);
            } else {
                res += c;
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
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

