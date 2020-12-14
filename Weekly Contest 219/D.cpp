#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for (auto &c : cuboids) {
            sort(c.begin(), c.end());
        }
        sort(cuboids.begin(), cuboids.end());
        vector<int> dp(n);
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] += cuboids[i][2];
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main() {
    return 0;
}