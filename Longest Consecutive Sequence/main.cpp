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
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 *
 * Solution:
 * Hash table
 */
class Solution {
public:
	map<int, bool> mp;

    int longestConsecutive(vector<int> &num) {
        mp.clear();
		int n = num.size();
		if (n == 0) return 0;
		for (int i = 0; i < n; i++)
			mp[num[i]] = false;
		int maxSeq = 0;
		for (int i = 0; i < n; i++)
			if (!mp[num[i]])
				maxSeq = max(maxSeq, findSeq(num[i]));
		return maxSeq;
    }
	
	int findSeq(int x) {
		mp[x] = true;
		int cnt = 1;
		int y = x + 1;
		while (mp.find(y) != mp.end()) {
			mp[y] = true;
			cnt++;
			y++;
		}
		y = x - 1;
		while (mp.find(y) != mp.end()) {
			mp[y] = true;
			cnt++;
			y--;
		}
		return cnt;
	}
};

int main() {
	int myint[] = {100, 4, 200, 3, 2, 1};
	vector<int> num(myint, myint + 6);
	Solution sol;
	cout << sol.longestConsecutive(num) << endl;
	return 0;
}

