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
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *	Integers in each row are sorted from left to right.
 *	The first integer of each row is greater than the last integer of the previous row.
 *
 * Solution:
 * Binary search.
 *
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
		if (n == 0) return false;
		int m = matrix[0].size();
		if (m == 0) return false;
		int lo = 0, hi = n * m - 1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			int val = matrix[mid / m][mid % m];
			if (val == target) return true;
			if (val < target) lo = mid + 1;
			else hi = mid - 1;			
		}
		return false;
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	vector<vector<int> > matrix(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 1; j < m; j++)
			cin >> matrix[i][j];
	int t;
	cin >> t;
	Solution sol;
	cout << sol.searchMatrix(matrix, t) << endl;
	return 0;
}

