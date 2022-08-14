#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

string res, p;
int n;
bool vst[10];
class Solution {
public:
    string smallestNumber(string pattern) {
        p = pattern;
        n = pattern.size();
        res = "";
        memset(vst, 0, sizeof(vst));
        for (int i = 1; i < 10; i++) {
            string s;
            s += (char)('0' + i);
            vst[i] = 1;
            dfs(s);
            vst[i] = 0;
            if (res != "") break;
        }
        return res;
    }

    void dfs(string s) {
        // cout << s << ' ' << res << endl;
        if (res != "") return;
        if (s.size() == n + 1) {
            res = s;
            return;
        }
        int sz = s.size();
        char d = p[sz - 1];
        int last = s[sz - 1] - '0';
        if (d == 'I') {
            for (int i = last + 1; i < 10; i++) {
                if (vst[i]) continue;
                s += (char)('0' + i);
                vst[i] = 1;
                dfs(s);
                s.pop_back();
                vst[i] = 0;
            }
        } else {
            for (int i = 1; i < last; i++) {
                if (vst[i]) continue;
                s += (char)('0' + i);
                vst[i] = 1;
                dfs(s);
                s.pop_back();
                vst[i] = 0;
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
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

