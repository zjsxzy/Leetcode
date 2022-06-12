#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int n = brackets.size();
        double res = 0;
        int prev = 0;
        for (int i = 0; i < n; i++) {
            int t = min(income, brackets[i][0]) - prev;
            res += 1.0 * t * brackets[i][1] / 100;
            prev = brackets[i][0];
            if (brackets[i][0] > income) break;
        }
        return res;
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

