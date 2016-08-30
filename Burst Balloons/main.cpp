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

class Solution {
public:
	vector<vector<int> > dp;
	vector<int> coins;
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
		coins.resize(n + 2);
		coins[0] = coins[n + 1] = 1;
		for (int i = 0; i < n; i++) {
			coins[i + 1] = nums[i];
		}
		
		dp.resize(n + 2);
		for (int i = 0; i < n + 2; i++) {
			dp[i].resize(n + 2);
		}

		return recur(0, n + 1);
    }

	int recur(int l, int r) {
		if (dp[l][r] != 0) return dp[l][r];
		if (r - l <= 1) return dp[l][r] = 0;
		int mx = 0;
		for (int i = l + 1; i < r; i++) {
			int temp = recur(l, i) + recur(i, r) + coins[l] * coins[i] * coins[r];
			mx = max(mx, temp);
		}
		return dp[l][r] = mx;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	return 0;
}
