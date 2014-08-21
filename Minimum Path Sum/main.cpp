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
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Solution:
 * DP. f(i, j) = min(f(i - 1, j), f(i, j - 1)) + grid[i][j].
 *
 */
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
		int n = grid.size(), m = grid[0].size();
		if (n == 0 || m == 0) return 0;
		vector<vector<int> > dp(n, vector<int>(m));
		dp[0][0] = grid[0][0];
		for (int i = 1; i < n; i++)
			dp[i][0] = dp[i - 1][0] + grid[i][0];
		for (int j = 1; j < m; j++)
			dp[0][j] = dp[0][j - 1] + grid[0][j];
		for (int i = 1; i < n; i++)
			for (int j = 1; j < m; j++)
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
		return dp[n - 1][m - 1];
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	return 0;
}

