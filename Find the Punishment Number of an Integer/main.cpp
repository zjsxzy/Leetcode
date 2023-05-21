#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    bool flag;
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (check(i)) {
                res += i * i;
            }
        }
        return res;
    }

    bool check(int x) {
        string s = to_string(x * x);
        flag = false;
        dfs(s, x, 0, 0, 0);
        return flag;
    }

    void dfs(string s, int x, int i, int sum, int curr) {
        if (i == s.size()) {
            if (sum + curr == x) flag = true;
            return;
        }
        dfs(s, x, i + 1, sum + curr, s[i] - '0');
        dfs(s, x, i + 1, sum, curr * 10 + s[i] - '0');
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

