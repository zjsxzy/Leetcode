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
 * Description: Given a set of distinct integers, S, return all possible subsets.
 *
 * Solution: Recursion.
 *
 */
class Solution {
public:
	vector<vector<int> > subList;
	int n;
	vector<int> S, cur;

	void search(int idx) {
		if (idx == n) {
			subList.push_back(cur);
			return;
		}
		search(idx + 1);

		cur.push_back(S[idx]);
		search(idx + 1);
		cur.pop_back();
	}

    vector<vector<int> > subsets(vector<int> &S) {
		n = S.size();
		cur.clear();
		sort(S.begin(), S.end());
		this->S = S;
		subList.clear();
		search(0);
		return subList;
    }
};
int main() {
	Solution sol;
	vector<int> a;
	a.PB(1); a.PB(2); a.PB(3);
	vector<vector<int> > ret = sol.subsets(a);
	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < ret[i].size(); j++)
			cout << ret[i][j] << " ";
		cout << endl;
	}
	return 0;
}

