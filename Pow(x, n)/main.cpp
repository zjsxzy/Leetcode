#include <map>
#include <climits>
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
 * Implement pow(x, n).
 *
 * Solution:
 * Quick Pow
 *
 */
class Solution {
public:
    double pow(double x, int n) {
		if (n < 0) {
			if (n > INT_MIN)
				return 1.0 / pow(x, -n);
			else return 1.0 / pow(x, -(n + 1)) * x;
		}
		double ret = 1.0;
		for (; n; n >>= 1) {
			if (n & 1) ret = ret * x;
			x = x * x;
		}
		return ret;
    }
};

int main() {
	Solution sol;
	printf("%.2f\n", sol.pow(2.0, -4));
	cout << INT_MIN << endl;
	cout << INT_MAX << endl;
	return 0;
}

