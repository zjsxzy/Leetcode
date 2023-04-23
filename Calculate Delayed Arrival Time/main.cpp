#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        int res = arrivalTime + delayedTime;
        if (res >= 24) res -= 24;
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

