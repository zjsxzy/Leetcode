#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        map<char, int> cnt;
        for (auto &s : words) {
            for (auto &c : s) {
                cnt[c]++;
            }
        }
        for (auto &[k, v] : cnt) {
            if (v % n != 0) return false;
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

