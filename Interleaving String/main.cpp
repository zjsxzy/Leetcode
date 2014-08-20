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
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 *
 * Solution:
 * DP. f(i,j) = (f(i-1,j) & s3[i+j]==s1[i]) | (f(i,j-1) & s3[i+j]==s2[j]).
 *
 */
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
		if (n1 + n2 != n3) return false;
		vector<vector<bool> > dp(n1 + 1, vector<bool>(n2 + 1));
		dp[0][0] = true;
		for (int i = 0; i <= n1; i++) {
			for (int j = 0; j <= n2; j++) {
				if (i > 0 && s3[i + j - 1] == s1[i - 1]) {
					dp[i][j] = dp[i][j] | dp[i - 1][j];
				}
				if (j > 0 && s3[i + j - 1] == s2[j - 1]) {
					dp[i][j] = dp[i][j] | dp[i][j - 1];
				}
			}
		}
		return dp[n1][n2];
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in2.txt", "r", stdin);
#endif
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	Solution sol;
	cout << sol.isInterleave(s1, s2, s3) << endl;
	return 0;
}

