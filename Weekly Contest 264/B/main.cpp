#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int nextBeautifulNumber(int n) {
        n++;
        while (!check(n)) {
            n++;
        }
        return n;
    }
    bool check(int x) {
        vector<int> cnt(10);
        while (x) {
            cnt[x % 10]++;
            x /= 10;
        }
        for (int i = 0; i < 10; i++) {
            if (cnt[i] == 0) continue;
            if (i != cnt[i]) return false;
        }
        return true;
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

