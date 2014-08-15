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
 * Description: Implement int sqrt(int x).
 *
 * Solution: Binary search.
 *
 */
class Solution {
public:
    int sqrt(int x) {
		int lo = 0, hi = min(x, 46340) + 1;
		int ret = -1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if ((long long)mid * mid <= x) {
				ret = mid;
				lo = mid + 1;
			}
			else hi = mid - 1;
		}
		return ret;
    }
};
int main() {
}

