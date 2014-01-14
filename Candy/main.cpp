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
 * There are N children standing in a line. Each child is assigned a rating value.
 * You are giving candies to these children subjected to the following requirements:
 *		Each child must have at least one candy.
 *		Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 *
 * Solution:
 * DP. f(i) = max(f(i-1)+1 | r[i] > r[i-1], f(i+1)+1 | r[i] > r[i+1])
 */
class Solution {
public:
    int candy(vector<int> &ratings) {
		int ret = 0, n = ratings.size();
		if (n == 0) return 0;
		vector<int> dp(n);
		for (int i = 0; i < n; i++)
			dp[i] = 1;
		for (int i = 1; i < n; i++) {
			if (ratings[i] > ratings[i - 1])
				dp[i] = max(dp[i], dp[i - 1] + 1);
		}
		for (int i = n - 2; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1])
				dp[i] = max(dp[i], dp[i + 1] + 1);
		}
		for (int i = 0; i < n; i++)
			ret += dp[i];
		return ret;
    }
};
int main() {
	int myint[] = {1, 2, 2};
	vector<int> r(myint, myint + 3);
	Solution sol;
	cout << sol.candy(r) << endl;
	return 0;
}

