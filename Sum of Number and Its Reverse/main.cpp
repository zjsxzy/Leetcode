#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for (int i = 0; i <= num; i++) {
            int t = rev(i);
            if (i + t == num) return true;
        }
        return false;
    }
    int rev(int x) {
        int res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
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

