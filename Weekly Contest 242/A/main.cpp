#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int count(string &s, char c) {
        int sum = 0, res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c) sum++;
            else sum = 0;
            res = max(res, sum);
        }
        return res;
    }
    bool checkZeroOnes(string s) {
        int l1 = count(s, '1'), l0 = count(s, '0');
        return l1 > l0;
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

