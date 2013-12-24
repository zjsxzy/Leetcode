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
 * Given an array of integers, every element appears three times except for one. Find that single one.
 *
 * Solution:
 * Check every bit of the numbers. If the number appears three times, then the ith bit must have 3k 1s.
 */
class Solution {
public:
    int singleNumber(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		int ret = 0;
		for (int i = 0; i < 32; i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (A[j] & (1 << i)) {
					cnt++;
				}
			}
			if (cnt % 3 != 0) ret |= 1 << i;
		}
		return ret;
    }
};

int main() {

}

