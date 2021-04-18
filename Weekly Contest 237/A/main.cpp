#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<char, int> cnt;
        for (auto x : sentence) {
            cnt[x]++;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt['a' + i] == 0) return false;
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

