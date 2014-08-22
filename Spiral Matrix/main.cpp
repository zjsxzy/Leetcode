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
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 *
 * Solution:
 * DFS implementation.
 *
 */
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
		ret.clear();
		this->matrix = matrix;
		n = matrix.size();
		if (n == 0) return ret;
		m = matrix[0].size();
		if (m == 0) return ret;
		vst.clear();
		vst.resize(n);
		for (int i = 0; i < n; i++) {
			vst[i].resize(m);
		}
		dfs(0, 0, 0);
		return ret;
    }
	
	void dfs(int r, int c, int dir) {
		// cout << r << " " << c << endl;
		ret.push_back(matrix[r][c]);
		if (ret.size() == n * m) return;
		vst[r][c] = true;
		int x = r + dx[dir], y = c + dy[dir];
		if (check(x, y)) dfs(x, y, dir);
		else {
			dir = (dir + 1) % 4;
			x = r + dx[dir]; y = c + dy[dir];
			dfs(x, y, dir);
		}
	}
	
	bool check(int r, int c) {
		return r >= 0 && r < n && c >= 0 && c < m && !vst[r][c];
	}
	
	int n, m;
	vector<vector<bool> > vst;
	vector<vector<int> > matrix;
	vector<int> ret;
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in2.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	vector<vector<int> > input(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> input[i][j];
	Solution sol;
	vector<int> ret = sol.spiralOrder(input);
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";
	cout << endl;
	return 0;
}

