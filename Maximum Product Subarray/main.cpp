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
 * Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 *
 * Solution:
 * DP. 
 * fmin[i] = min{A[i], fmax[i-1]*A[i], fmin[i-1]*A[i]}
 * fmax[i] = max{A[i], fmin[i-1]*A[i], fmax[i-1]*A[i]}
 *
 */
class Solution {
public:
    int maxProduct(int A[], int n) {
		vector<int> fmin(n), fmax(n);
		if (n == 0) return 0;
		fmin[0] = A[0];
		fmax[0] = A[0];
		int ret = A[0];
		for (int i = 1; i < n; i++) {
			fmin[i] = min(A[i], min(fmin[i - 1] * A[i], fmax[i - 1] * A[i]));
			fmax[i] = max(A[i], max(fmax[i - 1] * A[i], fmin[i - 1] * A[i]));
			ret = max(ret, fmax[i]);
		}
		return ret;
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int A[4] = {2, 3, -2, 4};
	Solution sol;
	cout << sol.maxProduct(A, 4) << endl;
	return 0;
}

