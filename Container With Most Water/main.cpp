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
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 * 
 * Solution:
 * Two points l and r moving toward the middle of the array.
 *
 */
class Solution {
public:
    int maxArea(vector<int> &height) {
		int ret = 0;
		for (int l = 0, r = height.size() - 1; r - l >= 1; ) {
			int low = min(height[l], height[r]);
			ret = max(ret, (r - l) * low);
			if (low == height[r]) r--;
			if (low == height[l]) l++;
		}
		return ret;
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	return 0;
}

