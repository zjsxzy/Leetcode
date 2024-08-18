#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector dp(n + 1, vector<long long>(2));
        dp[1][0] = energyDrinkA[0]; dp[1][1] = energyDrinkB[0];
        for (int i = 2; i <= n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 2][1]) + energyDrinkA[i - 1];
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0]) + energyDrinkB[i - 1];
        }
        return max(dp[n][0], dp[n][1]);
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

