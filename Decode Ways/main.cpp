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
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given an encoded message containing digits, determine the total number of ways to decode it.
 *
 * Solution:
 * DP. f(i) = (f(i-1) if 1<=s[i]<=9) + (f(i-2) if 10<=s[i-1..i]<=26).
 *
 */
class Solution {
public:
    int numDecodings(string s) {
		int n = s.size();
		if (n == 0) return 0;
		vector<int> dp(n + 1);
		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			if (s[i] >= '1' && s[i] <= '9')
				dp[i + 1] += dp[i];
			if (i + 1 < n) {
				string sub = s.substr(i, 2);
				int digit = (sub[0] - '0') * 10 + sub[1] - '0';
				if (digit >= 10 && digit <= 26)
					dp[i + 2] += dp[i];
			}
		}
		return dp[n];
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	string s;
	cin >> s;
	Solution sol;
	cout << sol.numDecodings(s) << endl;
	return 0;
}

