#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size(), res = n + 1;
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                res = min(res, (i - startIndex + n) % n);
                res = min(res, (startIndex - i + n) % n);
            }
        }
        if (res == n + 1) res = -1;
        return res;
    }
};

void solve() {
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

