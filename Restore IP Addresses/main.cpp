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
 * Description: Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 *
 * Solution: Recursion.
 *
 */
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
		vector<string> ret;
		string ip;
		dfs(s, ret, ip, 0, 0);
		return ret;
    }

	void dfs(string &s, vector<string> &ans, string &ip, int dep, int start) {
		if (dep == 4 || start == s.size()) {
			if (dep == 4 && start == s.size()) {
				ans.push_back(ip);
			}
			return;
		}
		int num = 0;
		for (int i = start; i <= start + 2 && i < s.size(); i++) {
			num = num * 10 + s[i] - '0';
			if (num >= 0 && num <= 255) {
				int orig = ip.size();
				if (orig != 0) {
					ip += ".";
				}
				ip += s.substr(start, i - start + 1);
				dfs(s, ans, ip, dep + 1, i + 1);
				ip.resize(orig);
				if (num == 0) break;
			}
		}
	}
};
int main() {
}

