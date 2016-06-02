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
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 *
 * Solution:
 * DP. F(i) = max{F(i - 1) + A[i], A[i]}.
 */
class Solution {
public:
    int maxSubArray(int A[], int n) {
		int sum = 0, maxSum = INT_MIN;
		for (int i = 0; i < n; i++) {
			if (sum > 0) {
				sum += A[i];
			} else {
				sum = A[i];
			}
			maxSum = max(maxSum, sum);
		}
		return maxSum;
    }
};
int main() {
	int A[9] = {-2,1,-3,4,-1,2,1,-5,4};
	Solution sol;
	cout << sol.maxSubArray(A, 9) << endl;
	return 0;
}

