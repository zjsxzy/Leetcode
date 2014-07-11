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
 * Description: Find longest palindromic substrings.
 * 
 * Solution: Manchester algorithm O(n).
 *
 */
const int MAXN = 1000 + 5;
class Solution {
public:
	string s;
	char str[MAXN << 1];
	int dp[MAXN << 1];
	pair<int, int> Manchester() {
		int n = s.size();
		int j = 0;
		for (int i = 0; i < n; i++) {
			str[j++] = '#';
			str[j++] = s[i];
		}
		str[j++] = '#';
		n = j;

		int res = 0, mid = -1;
		int right = -1, id = -1;
		for (int i = 0; i < n; i++) {
			int r = 1;
			if (right >= i) {
				r = max(r, min(right - i + 1, dp[2 * id - i]));
			}
			while ((i - r + 1 >= 0 && i + r - 1 < n) && str[i - r + 1] == str[i + r - 1])
				r++;
			r--;
			if (i + r - 1 > right) {
				right = i + r - 1;
				id = i;
			}
			dp[i] = r;
			if (r > res) {
				res = r;
				mid = i;
			}
		}
		return MP(mid - res + 1, mid + res - 1);
	}
	
    string longestPalindrome(string s) {
        this->s = s;
		string ans;
		pair<int, int> pos = Manchester();
		// cout << pos.first << " " << pos.second << endl;
		for (int i = pos.first; i <= pos.second; i++) {
			if (str[i] == '#') continue;
			ans += str[i];
		}
		return ans;
    }
};
int main() {
	string s = "abbaccccc";
	Solution sol;
	string ans = sol.longestPalindrome(s);
	cout << ans << endl;
	return 0;
}

