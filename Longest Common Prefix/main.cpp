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
 * Write a function to find the longest common prefix string amongst an array of strings.
 *
 * Solution:
 * Enumerate the prefix of the first string and check incrementally.
 */
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int n = strs.size();
		if (n == 0) return "";
		string ret = "";
		for (int k = 0; k < strs[0].size(); k++) {
			char ch = strs[0][k];
			bool flag = true;
			for (int i = 1; i < n; i++) {
				if (strs[i].size() <= k) {
					flag = false; break;
				}
				if (strs[i][k] != ch) {
					flag = false; break;
				}
			}
			if (!flag) break;
			else ret += ch;
		}
		return ret;
    }
};

int main() {
	string s[] = {"aab", "aac", "aaa"};
	vector<string> str(s, s + 3);
	Solution sol;
	cout << sol.longestCommonPrefix(str) << endl;
	return 0;
}

