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

/*
 * Description:
 * Follow up for "Unique Paths":
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 *
 * Solution:
 * DP. f(i, j) = obstacle[i][j] == 1 ? f(i-1, j) + f(i, j-1) : 0.
 *
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int n = obstacleGrid.size();
		if (n == 0) return 0;
		int m = obstacleGrid[0].size();
		if (m == 0) return 0;
		vector<vector<int> > dp(n, vector<int>(m));
		dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
		for (int i = 1; i < m; i++)
			dp[0][i] = obstacleGrid[0][i] == 0 ? dp[0][i - 1] : 0;
		for (int i = 1; i < n; i++)
			dp[i][0] = obstacleGrid[i][0] == 0 ? dp[i - 1][0] : 0;
		for (int i = 1; i < n; i++)
			for (int j = 1; j < m; j++)
				dp[i][j] = obstacleGrid[i][j] == 0 ? dp[i - 1][j] + dp[i][j - 1] : 0;
		return dp[n - 1][m - 1];
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	return 0;
}

