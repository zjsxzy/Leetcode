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
 * Description: Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 * You have the following 3 operations permitted on a word:
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
 * 
 * Solution: DP. f(i, j) = min{f(i - 1, j - 1) + (word1[i] != word2[j]), f(i - 1, j) + 1, f(i, j - 1) + 1}
 * 
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
		int n = word1.size(), m = word2.size();
		vector<vector<int> > dp(n + 1, vector<int>(m + 1));
		for (int i = 1; i <= n; i++)
			dp[i][0] = i;
		for (int j = 1; j <= m; j++)
			dp[0][j] = j;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1);
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
			}
		}
		return dp[n][m];
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	string a, b;
	cin >> a >> b;
	Solution sol;
	cout << sol.minDistance(a, b) << endl;
	return 0;
}

