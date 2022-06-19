#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    string greatestLetter(string s) {
        set<char> st;
        for (auto c: s) {
            st.insert(c);
        }
        char r = '!';
        for (char c = 'a'; c <= 'z'; c++) {
            if (st.find(c) != st.end()) {
                if (st.find(toupper(c)) != st.end()) {
                    r = toupper(c);
                }
            }
        }
        string res;
        if (r != '!') res += r;
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

