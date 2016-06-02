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
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 *
 * Solution:
 * Brute force
 */
class Solution {
public:
    int removeDuplicates(int A[], int n) {
		int cur = 0, i = 0;
		for (; i < n; ) {
			A[cur++] = A[i];
			while (i < n && A[i] == A[cur - 1])
				i++;
		}
		return cur;
    }
};

int main() {
	int A[] = {1, 1, 2};
	Solution sol;
	cout << sol.removeDuplicates(A, 3) << endl;
	return 0;
}

