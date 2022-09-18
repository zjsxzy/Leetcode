#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int smallestEvenMultiple(int n) {
        int g = gcd(2, n);
        return 2 * n / g;
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

