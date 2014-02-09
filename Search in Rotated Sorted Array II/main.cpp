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
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 *
 * Solution:
 * Find the pivot first, but if the first element equals the last one, increment the first index until they are not equal, then use binary search.
 */
class Solution {
public:
	int FindPivot(int A[], int n) {
		int lo = 0, hi = n - 1;
		while (lo < hi && A[lo] == A[hi]) {
			lo++;
		}
		int last = A[n - 1], ret = -1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (A[mid] <= last) {
				ret = mid;
				hi = mid - 1;
			} else lo = mid + 1;
		}
		return ret;
	}
    bool search(int A[], int n, int target) {
		if (n == 0) return -1;
		int lo = 0, hi = n - 1;
		int pos = FindPivot(A, n);
		if (target > A[n - 1]) {
			lo = 0, hi = pos - 1;
		} else {
			lo = pos, hi = n - 1;
		}
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (A[mid] == target) return true;
			if (A[mid] < target) lo = mid + 1;
			else hi = mid - 1;
		}
		return false;
    }
};
int main() {
	int A[] = {2, 2, 2, 0, 2, 2};
	int B[] = {1};
	Solution sol;
	cout << sol.search(B, 1, 1) << endl;
	return 0;
}

