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
 * There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 * Solution:
 * Divide and Conquer
 */
class Solution {
public:
	int findKth(int k, int A[], int startA, int lenA, int B[], int startB, int lenB) {
		if (lenA > lenB) {
			return findKth(k, B, startB, lenB, A, startA, lenA);
		}
		if (lenA == 0) {
			return B[startB + k];
		}
		if (k == 0) {
			return min(A[startA], B[startB]);
		}
		int midA = min((k + 1) / 2, lenA);
		int midB = k + 1 - midA;
		if (A[startA + midA - 1] < B[startB + midB - 1]) {
			return findKth(k - midA, A, startA + midA, lenA - midA, B, startB, lenB);
		} else {
			return findKth(k - midB, A, startA, lenA, B, startB + midB, lenB - midB);
		}
	}

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (n + m == 0) return 0.0;
		if ((n + m) & 1) {
			return findKth((n + m) / 2, A, 0, m, B, 0, n);
		} else {
			int s = findKth((n + m) / 2, A, 0, m, B, 0, n);
			int t = findKth((n + m) / 2 - 1, A, 0, m, B, 0, n);
			return (s + t) * 0.5;
		}
    }
};

int main() {
	int A[] = {1, 2, 3, 4};
	int B[] = {7, 8, 9, 10};
	Solution sol;
	cout << sol.findMedianSortedArrays(A, 4, B, 4) << endl;
	return 0;
}

