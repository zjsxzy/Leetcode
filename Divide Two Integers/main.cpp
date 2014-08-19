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
 * Description: Divide two integers without using multiplication, division and mod operator.
 * 
 * Solution: Minus the divisor until 0 with bit manipulation.
 *
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
		int ret = dividePos(abs(dividend), abs(divisor));
		if (((dividend ^ divisor) & (1 << 31)) != 0)
			ret = -ret;
		return ret;
    }
	
	int dividePos(int dividend, int divisor) {
		int ret = 0;
		for (int i = bits(dividend) - bits(divisor); i >= 0; i--) {
			if (dividend - (divisor << i) >= 0) {
				ret |= (1 << i);
				dividend -= divisor << i;
			}
		}
		return ret;
	}
	
	int bits(int x) {
		int i = 31;
		for (; i >= 0 && (x & (1 << i)) == 0; i--);
		return i;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int a, b;
	cin >> a >> b;
	Solution sol;
	cout << sol.divide(a, b) << endl;
	return 0;
}

