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
 * Given a number represented as an array of digits, plus one to the number.
 *
 * Solution:
 * Brute force
 */
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
		int n = digits.size();
		if (n == 0) return digits;
		int i = n - 1;
		while (i >= 0 && digits[i] == 9)
			i--;
		if (i < 0) {
			vector<int> digits2(n + 1);
			digits2[0] = 1;
			return digits2;
		}
		digits[i]++;
		for (i = i + 1; i < n; i++)
			digits[i] = 0;
		return digits;
    }
};
int main() {
}

