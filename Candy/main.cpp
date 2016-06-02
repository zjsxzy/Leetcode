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
 * Sort by ratings first.
 * Then DP. f(i) = max(f(i-1)+1 | r[i] > r[i-1], f(i+1)+1 | r[i] > r[i+1])
 */
class Solution {
public:
    int candy(vector<int> &ratings) {
		int ret = 0, n = ratings.size();
		if (n == 0) return 0;
		vector<int> dp(n);
		vector<pair<int, int> > idx(n);
		for (int i = 0; i < n; i++) {
			idx[i] = make_pair(ratings[i], i);
			dp[i] = 1;
		}
		sort(idx.begin(), idx.end());
		for (int i = 0; i < n; i++) {
			int p = idx[i].second;
			if (p - 1 >= 0 && ratings[p - 1] < ratings[p]) {
				dp[p] = max(dp[p], dp[p - 1] + 1);
			}
			if (p + 1 < n && ratings[p + 1] < ratings[p]) {
				dp[p] = max(dp[p], dp[p + 1] + 1);
			}
		}
		for (int i = 0; i < n; i++)
			ret += dp[i];
		return ret;
    }
};
int main() {
	int myint[] = {1, 3, 5};
	vector<int> r(myint, myint + 3);
	Solution sol;
	int myint2[] = {2, 2};
	vector<int> r2(myint2, myint2 + 2);
	cout << sol.candy(r) << endl;
	cout << sol.candy(r2) << endl;
	return 0;
}

