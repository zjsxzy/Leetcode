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
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 * Solution:
 * Brute force
 */
class Solution {
public:
    int removeDuplicates(int A[], int n) {
		int cur = 0, i = 0;
		for (; i < n; ) {
			int j = i + 1;
			while (j < n && A[j] == A[i])
				j++;
			A[cur++] = A[i];
			if (j - i >= 2)
				A[cur++] = A[i];
			i = j;
		}
		return cur;
    }
};
int main() {
	int A[] = {1, 1, 1, 2, 2, 3};
	Solution sol;
	cout << sol.removeDuplicates(A, 6) << endl;
	return 0;
}

