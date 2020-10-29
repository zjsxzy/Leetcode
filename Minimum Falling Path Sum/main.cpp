#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int MAXN = 105;
int dp[MAXN][MAXN];

class Solution {
    public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        memset(dp, 10000, sizeof(dp));
        for (int j = 0; j < n; j++) {
            dp[0][j] = A[0][j];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + A[i][j]);
                }
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + A[i][j]);
                if (j < n - 1) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + A[i][j]);
                }
            }
        }
        int res = INT_MAX;
        for (int j = 0; j < n; j++) {
            res = min(res, dp[n - 1][j]);
        }
        return res;
    }
};

int main() {
}

