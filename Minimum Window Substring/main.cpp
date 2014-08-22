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
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 *
 * Solution:
 * Two pointers.
 *
 */
const int NUM_CHAR = 128;
class Solution {
public:
    string minWindow(string S, string T) {
		vector<int> cntT(NUM_CHAR), cntS(NUM_CHAR);
		for (int i = 0; i < T.size(); i++)
			cntT[(int)T[i]]++;
		int sum = 0;
		for (int i = 0; i < NUM_CHAR; i++)
			sum += (cntT[i] > 0);
		int l = 0, r = 0;
		int minL = S.size() + 1;
		string ret = "";
		int match = 0;
		while (true) {
			if (match < sum) {
				if (r == S.size()) break;
				int ch = (int)S[r];
				cntS[ch]++;
				if (cntT[ch] > 0 && cntS[ch] == cntT[ch]) match++;
				r++;
			} else {
				if (r - l < minL) {
					minL = r - l;
					ret = S.substr(l, r - l);
				}
				char ch = (int)S[l];
				cntS[ch]--;
				if (cntT[ch] > 0 && cntS[ch] < cntT[ch]) match--;
				l++;
			}
		}
		return ret;
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in2.txt", "r", stdin);
#endif
	string s, t;
	cin >> s >> t;
	Solution sol;
	cout << sol.minWindow(s, t) << endl;
	return 0;
}

