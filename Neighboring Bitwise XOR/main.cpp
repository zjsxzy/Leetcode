#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        if (n == 1) return derived[0] == 0;
        vector<int> ori(n);
        ori[0] = 1;
        for (int i = n - 1; i > 0; i--) {
            ori[i] = ori[(i + 1) % n] ^ derived[i];
        }
        if (derived[0] == ori[0] ^ ori[1]) return true;
        ori[0] = 0;
        for (int i = n - 1; i > 0; i--) {
            ori[i] = ori[(i + 1) % n] ^ derived[i];
        }
        if (derived[0] == ori[0] ^ ori[1]) return true;
        return false;
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

