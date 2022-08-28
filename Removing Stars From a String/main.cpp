#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    string removeStars(string s) {
        vector<char> st;
        for (auto c: s) {
            if (c != '*') {
                st.push_back(c);
            } else {
                st.pop_back();
            }
        }
        string res;
        for (auto c: st) res += c;
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

