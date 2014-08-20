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
 * Given a string S and a string T, count the number of distinct subsequences of T in S.
 *
 * Solution:
 * DP. f(i, j) = f(i-1, j) + (f(i-1, j-1) if S[i]==T[j]).
 *
 */
class Solution {
public:
    int numDistinct(string S, string T) {
		int n = S.size(), m = T.size();
		vector<vector<int> > dp(n + 1, vector<int>(m + 1));
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			dp[i][0] = 1;
			for (int j = 1; j <= m; j++) {
				dp[i][j] = dp[i - 1][j];
				if (S[i - 1] == T[j - 1])
					dp[i][j] += dp[i - 1][j - 1];
			}
		}
		return dp[n][m];
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	string s, t;
	cin >> s >> t;
	Solution sol;
	cout << sol.numDistinct(s, t) << endl;
	return 0;
}

