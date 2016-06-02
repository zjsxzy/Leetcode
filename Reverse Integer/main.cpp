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
 * Reverse digits of an integer.
 *
 * Solution:
 * Brute force
 */
class Solution {
public:
    int reverse(int x) {
		if (x < 0) return -reverse(-x);
		int y = 0;
		for (; x > 0; x /= 10) {
			y *= 10;
			y += x % 10;
		}
		return y;
    }
};
int main() {
}

