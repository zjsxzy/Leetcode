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
 * Given n and k, return the kth permutation sequence.
 *
 * Solution:
 * Math. Calculate the kth permutation sequence.
 */ 
class Solution {
public:
    string getPermutation(int n, int k) {
		k--;
		int fact = 1;
		for (int i = 2; i <= n; i++)
			fact *= i;
		if (k >= fact) return "";
		vector<bool> used(n);
		string res = "";
		for (int i = n; i >= 1; i--) {
			fact /= i;
			int m = k / fact;
			k %= fact;
			for (int j = 0; j < n; j++) {
				if (used[j]) continue;
				if (m == 0) {
					used[j] = true;
					res += (char)('0' + j + 1);
					break;
				}
				m--;
			}
		}
		return res;
    }
};
int main() {
	Solution sol;
	cout << sol.getPermutation(1, 1) << endl;
	return 0;
}

