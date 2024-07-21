#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int minChanges(int n, int k) {
        int res = 0;
        for (int i = 0; i < 30; i++) {
            if (n >> i & 1) {
                if (!(k >> i & 1)) {
                    res++;
                }
            } else {
                if (k >> i & 1) return -1;
            }
        }
        return res;
    }
};

void solve() {
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
       solve();
    }
    return 0;
}

