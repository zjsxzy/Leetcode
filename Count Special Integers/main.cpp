#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int countSpecialNumbers(int n) {
        vector<int> digits;
        int x = n + 1;
        while (x) {
            digits.push_back(x % 10);
            x /= 10;
        }
        reverse(digits.begin(), digits.end());
        int res = 0, sz = digits.size();
        for (int i = 1; i < sz; ++i) {
            res += 9 * A(9, i - 1);
        }

        unordered_set<int> visited;
        for (int i = 0; i < sz; i++) {
            for (int j = i > 0 ? 0 : 1; j < digits[i]; j++) {
                if (visited.count(j)) continue;
                res += A(9 - i, sz - i - 1);
            }
            if (visited.count(digits[i])) break;
            visited.insert(digits[i]);
        }
        return res;
    }
    int A(int m, int n) {
        return n == 0 ? 1 : A(m, n - 1) * (m - n + 1);
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

