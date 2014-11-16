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
 * Descrption:
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 *
 * Solution:
 * Binary Search.
 *
 */
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int lo = 0, hi = n - 1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (A[mid] == target) return mid;
			if (target < A[mid]) hi = mid - 1;
			else lo = mid + 1;
		}
		return lo;
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int A[] = {1, 3, 5};
	Solution sol;
	cout << sol.searchInsert(A, 3, 7) << endl;
	return 0;
}

