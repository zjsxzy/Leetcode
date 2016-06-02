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
 * The gray code is a binary numeral system where two successive values differ in only one bit.
 * Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
 *
 * Solution:
 * Construction.
 */
class Solution {
public:
    vector<int> grayCode(int n) {
		vector<int> ret;
		ret.push_back(0);
		if (n == 0) return ret;
		ret.push_back(1);
		int bit = 1;
		for (int i = 2; i <= n; i++) {
			bit <<= 1;
			for (int j = ret.size() - 1; j >= 0; j--) {
				ret.push_back(ret[j] | bit);
			}
		}
		return ret;
    }
};
int main() {
}

