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
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 * 
 * Solution:
 * Enumerate all possible situations
 *
 */
class Solution {
public:
	int N, K;
	vector<int> cur;
	vector<vector<int> > numList;
	void dfs(int n, int k) {
		if (k == K) {
			vector<int> num;
			FOREACH(it, cur)
				num.PB(*it);
			numList.PB(num);
			return;
		}
		if (n > N) return;
		dfs(n + 1, k);
		cur.PB(n);
		dfs(n + 1, k + 1);
		cur.pop_back();
	}
    vector<vector<int> > combine(int n, int k) {
		N = n; K = k;
		cur.clear();
		numList.clear();
		dfs(1, 0);
		return numList;
    }
};

int main() {
	Solution sol;
	vector<vector<int> > ans = sol.combine(4, 2);
	for (int i = 0; i < ans.size(); i++) {
		FOREACH(it, ans[i])
			cout << *it << " ";
		cout << endl;
	}
	return 0;
}

