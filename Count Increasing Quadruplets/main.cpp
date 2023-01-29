#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 4005;
int f[maxn][maxn], g[maxn][maxn];
class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i <= n + 1; i++) for (int j = 0; j <= n + 1; j++) f[i][j] = g[i][j] = 0;
        for (int i = 1; i <= n; i++) f[i][nums[i - 1]] = g[i][nums[i - 1]] = 1;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) f[i][j] += f[i][j - 1];
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) f[i][j] += f[i - 1][j];
        for (int i = n; i > 0; i--) for (int j = n; j > 0; j--) g[i][j] += g[i][j + 1];
        for (int i = n; i > 0; i--) for (int j = n; j > 0; j--) g[i][j] += g[i + 1][j];

        long long res = 0;
        for (int j = 1; j <= n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[k - 1] < nums[j - 1]) {
                    res += 1LL * f[j - 1][nums[k - 1] - 1] * g[k + 1][nums[j - 1] + 1];
                }
            }
        }
        return res;
    }
};

void solve() {
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

