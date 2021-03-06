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
 * Given an array of integers, every element appears twice except for one. Find that single one.
 *
 * Solution:
 * We know that x^0 = x, x^x = 0, so the answer is xor of all the numbers.
 *
 */
class Solution {
public:
    int singleNumber(int A[], int n) {
		int ret = 0;
		for (int i = 0; i < n; i++)
			ret ^= A[i];
		return ret;
    }
};

int main() {
	return 0;
}

