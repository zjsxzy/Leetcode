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
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 *
 * Solution:
 * Find the pivot first then use binary search.
 */
class Solution {
public:
	int FindPivot(int A[], int n) {
		int lo = 0, hi = n - 1;
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
    int search(int A[], int n, int target) {
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
			if (A[mid] == target) return mid;
			if (A[mid] < target) lo = mid + 1;
			else hi = mid - 1;
		}
		return -1;
    }
};
int main() {
	int A[] = {4, 5, 6, 7, 0, 1, 2};
	Solution sol;
	cout << sol.search(A, 7, 5) << endl;
	cout << sol.search(A, 7, 1) << endl;
}

