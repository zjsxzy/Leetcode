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
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * How many possible unique paths are there?
 *
 * Solution:
 * DP. f(i, j) = f(i - 1, j) + f(i, j - 1).
 *
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) return 0;
		vector<vector<int> > dp(m, vector<int>(n));
		dp[0][0] = 1;
		for (int i = 1; i < n; i++)
			dp[0][i] = 1;
		for (int i = 1; i < m; i++)
			dp[i][0] = 1;
		for  (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		return dp[m - 1][n - 1];
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	return 0;
}

