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
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 *
 * Solution:
 * DP. Calculate the highest element in every one's left and right.
 */
class Solution {
public:
    int trap(int A[], int n) {
		int Max = 0;
		vector<int> ll(n);
		for (int i = 0; i < n; i++) {
			Max = max(Max, A[i]);
			ll[i] = Max;
		}
		int right = 0;
		int sum = 0;
		for (int i = n - 1; i >= 0; i--) {
			right = max(right, A[i]);
			sum += min(ll[i], right) - A[i];
		}
		return sum;
    }
};
int main() {
}

