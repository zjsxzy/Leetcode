#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    string digitSum(string s, int k) {
        string t = s;
        while (t.size() > k) {
            int n = t.size();
            string next = "";
            for (int i = 0; i < n; i += k) {
                int sum = 0;
                for (int j = 0; j < k; j++) {
                    if (i + j < n) {
                        sum += t[i + j] - '0';
                    }
                }
                next += to_string(sum);
            }
            t = next;
        }
        return t;
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

