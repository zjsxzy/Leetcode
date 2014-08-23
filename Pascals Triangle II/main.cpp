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
 * Given an index k, return the kth row of the Pascal's triangle.
 *
 * Solution:
 * Construction, implementation.
 *
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1);
		row[0] = 1;
		for (int i = 1; i <= rowIndex; i++) {
			row[i] = 1;
			for (int j = i - 1; j >= 1; j--)
				row[j] = row[j - 1] + row[j];
			row[0] = 1;
		}
		return row;
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	Solution sol;
	vector<int> ret = sol.getRow(n);
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";
	cout << endl;
	return 0;
}

