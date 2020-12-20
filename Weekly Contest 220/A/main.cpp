#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    string reformatNumber(string number) {
        string s;
        for (char &c : number) {
            if (c != '-' && c != ' ') s += c;
        }
        string res;
        int i = 0;
        for (; i + 4 < s.size(); i += 3) {
            res += s.substr(i, 3);
            res += '-';
        }

        if (s.size() - i < 4) {
            res += s.substr(i, s.size() - i);
        } else {
            res += s.substr(i, 2); res += "-";
            res += s.substr(i + 2, 2);
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
    solve();
    return 0;
}

