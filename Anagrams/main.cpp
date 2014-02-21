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
 * Given an array of strings, return all groups of strings that are anagrams.
 *
 * Solution:
 * Hash table.
 */
class Solution {
public:
	vector<int> getFreq(string str) {
		vector<int> freq(26);
		for (int i = 0; i < str.size(); i++) {
			freq[str[i] - 'a']++;
		}
		return freq;
	}
    vector<string> anagrams(vector<string> &strs) {
		map<vector<int>, vector<string> > groupTable;
		for (int i = 0; i < strs.size(); i++) {
			vector<int> key = getFreq(strs[i]);
			groupTable[key].push_back(strs[i]);
		}
		vector<string> ret;
		map<vector<int>, vector<string> >::iterator it;
		for (it = groupTable.begin(); it != groupTable.end(); it++) {
			vector<string> temp = (it->second);
			if (temp.size() > 1) {
				for (int i = 0; i < temp.size(); i++)
					ret.push_back(temp[i]);
			}
		}
		return ret;
    }
};
int main() {
}

