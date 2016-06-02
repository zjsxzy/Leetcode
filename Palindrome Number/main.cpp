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
 * Decription:
 * Determine whether an integer is a palindrome. Do this without extra space.
 * Solution:
 * Brute force
 *
 */
class Solution {
public:
    bool isPalindrome(int x) {
		if (x < 0) return false;
        long long ori = x, y = 0;
		for (; x; x /= 10) {
			y = y * 10 + x % 10;
		}
		return ori == y;
    }
};

int main() {
	Solution sol;
	cout << sol.isPalindrome() << endl;
	return 0;
}

