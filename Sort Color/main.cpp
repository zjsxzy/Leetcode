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
 * Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 *
 * Solution:
 * Three pointers p01, p1, p2 to maintain 0, 1, 2.
 *
 */
class Solution {
public:
    void sortColors(int A[], int n) {
        int p0 = 0, p1 = 0, p2 = n - 1;
		while (p1 <= p2) {
			if (A[p1] == 0) {
				swap(A[p0], A[p1]);
				p0++; p1++;
			} else if (A[p1] == 1) {
				p1++;
			} else { // A[p1] == 2
				swap(A[p1], A[p2]);
				p2--;
			}
		}
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	return 0;
}

