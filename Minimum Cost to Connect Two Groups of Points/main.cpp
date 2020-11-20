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
#include <cassert>
#include <climits>
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


const int inf = 1000000;
int cs[12][5000], dp[12][5000];
class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size(), m = cost[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (1 << m); j++) {
                cs[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (1 << m); j++) {
                for (int k = 0; k < m; k++) {
                    if (j & (1 << k)) {
                        cs[i][j] += cost[i][k];
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (1 << m); j++) {
                if (i == 0) dp[i][j] = cs[i][j];
                else dp[i][j] = inf;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < (1 << m); j++) {
                // at least choose one
                for (int k = 0; k < m; k++) {
                    dp[i][j | (1 << k)] = min(dp[i][j | (1 << k)], dp[i - 1][j] + cost[i][k]);
                }
                int rest = (1 << m) - 1 - j;
                for (int k = rest; k >= 0; k = rest & (k - 1)) {
                    dp[i][j | k] = min(dp[i][j | k], dp[i - 1][j] + cs[i][k]);
                }
                /*
                for (int k = 1; k < (1 << m); k++) {
                    dp[i][j | k] = min(dp[i][j | k], dp[i - 1][k] + cs[i][j]);
                }
                */
            }
        }
        return dp[n - 1][(1 << m) - 1];
    }
};

int main() {
}

