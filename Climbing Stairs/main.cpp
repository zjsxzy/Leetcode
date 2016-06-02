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
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 *
 * Solution:
 * DP. f(i) = f(i - 1) + f(i - 2)
 */
class Solution {
public:
    int climbStairs(int n) {
		vector<int> dp(n + 1);
		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			if (i + 1 <= n) dp[i + 1] += dp[i];
			if (i + 2 <= n) dp[i + 2] += dp[i];
		}
		return dp[n];
    }
};
int main() {
}

