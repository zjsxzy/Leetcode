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
 * Description: Given an unsorted integer array, find the first missing positive integer.
 *
 * Solution: Construction, try to make A[0]~A[n] be 1~n, then the first missing positive is i != A[i] - 1.
 *
 */
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
		for (int i = 0; i < n; ) {
			if (A[i] >= 1 && A[i] <= n && A[A[i] - 1] != A[i]) {
				int a = i, b = A[i] - 1;
				int temp = A[a];
				A[a] = A[b];
				A[b] = temp;
			} else i++;
		}
		for (int i = 0; i < n; i++)
			if (i != A[i] - 1) return i + 1;
		return n + 1;
    }
};
int main() {
	int a[] = {2, 1};
	Solution sol;
	cout << sol.firstMissingPositive(a, 2) << endl;
	return 0;
}

