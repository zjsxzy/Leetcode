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
 * Description:
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Solution:
 * Two pointers with hash.
 *
 */
const int MAXN = 128;
int vst[MAXN];
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		memset(vst, 0, sizeof(vst));
		int head = 0, tail = 0;
		for (; tail < s.size() && vst[(int)s[tail]] == false; tail++)
			vst[(int)s[tail]] = true;
		int res = tail;
		while (tail < s.size()) {
			vst[(int)s[head]] = false; head++;
			for (; tail < s.size() && vst[(int)s[tail]] == false; tail++)
				vst[(int)s[tail]] = true;
			res = max(res, tail - head);
		}
		return res;
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	string s;
	cin >> s;
	Solution sol;
	cout << sol.lengthOfLongestSubstring(s) << endl;
	return 0;
}

