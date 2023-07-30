#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    string minimumString(string a, string b, string c) {
        string res = f(f(a, b), c);
        string t = f(f(a, c), b);
        if (t.size() < res.size() || (t.size() == res.size() && t < res)) res = t;
        t = f(f(b, c), a);
        if (t.size() < res.size() || (t.size() == res.size() && t < res)) res = t;
        return res;
    }

    string f(string a, string b) {
        std::size_t found = a.find(b);
        if (found != std::string::npos) return a;
        found = b.find(a);
        if (found != std::string::npos) return b;

        int n = a.size(), m = b.size();
        string res = min(a + b, b + a);
        for (int i = 1; i <= n; i++) {
            if (a.substr(n - i, i) == b.substr(0, i)) {
                string t = a.substr(0, n - i) + b;
                if (t.size() < res.size() || (t.size() == res.size() && t < res)) res = t;
            }
        }
        for (int i = 1; i <= m; i++) {
            if (b.substr(m - i, i) == a.substr(0, i)) {
                string t = b.substr(0, m - i) + a;
                if (t.size() < res.size() || (t.size() == res.size() && t < res)) res = t;
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

