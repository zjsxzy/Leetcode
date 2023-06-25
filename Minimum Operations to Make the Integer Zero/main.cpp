#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long long n1 = num1, n2 = num2;
        for (int i = 1; i <= 100000; i++) {
            long long x = n1 - i * n2;
            if (x <= 0) continue;
            int b = 0;
            for (int i = 0; i < 60; i++) {
                b += (x >> i & 1);
            }
            if (i >= b && i <= x) return i;
        }
        return -1;
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

