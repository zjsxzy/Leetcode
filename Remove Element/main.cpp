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
 * Given an array and a value, remove all instances of that value in place and return the new length.
 *
 * Solution:
 * Brute force
 */
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
		int cur = 0;
		for (int i = 0; i < n; i++) {
			if (A[i] == elem) continue;
			A[cur++] = A[i];
		}
		return cur;
    }
};
int main() {
}

