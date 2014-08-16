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
 * Description: Given a roman numeral, convert it to an integer.
 *
 * Solution: Implementation.
 *
 */
class Solution {
public:
    int romanToInt(string s) {
		map<char, int> mp;
		mp['I'] = 1; mp['V'] = 5; mp['X'] = 10;
		mp['L'] = 50; mp['C'] = 100; mp['D'] = 500; mp['M'] = 1000;
		int res = 0, n = s.size();
		s.push_back(s[n - 1]);
		for (int i = 0; i < n; i++) {
			if (mp[s[i]] >= mp[s[i + 1]])
				res += mp[s[i]];
			else res -= mp[s[i]];
		}
		return res;
    }
};
int main() {
}

