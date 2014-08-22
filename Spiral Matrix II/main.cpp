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
 * Given an integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.
 *
 * Solution:
 * DFS implementation.
 *
 */
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
		this->n = n;
        matrix.clear();
		if (n == 0) return matrix;
		vst.clear();
		matrix.resize(n);
		vst.resize(n);
		for (int i = 0; i < n; i++) {
			matrix[i].resize(n);
			vst[i].resize(n);
		}
		dfs(0, 0, 0, 1);
		return matrix;
    }
	
	void dfs(int r, int c, int dir, int num) {
		// cout << r << " " << c << endl;
		matrix[r][c] = num;
		if (num == n * n) return;
		vst[r][c] = true;
		int x = r + dx[dir], y = c + dy[dir];
		if (check(x, y)) dfs(x, y, dir, num + 1);
		else {
			dir = (dir + 1) % 4;
			x = r + dx[dir]; y = c + dy[dir];
			dfs(x, y, dir, num + 1);
		}
	}
	
	bool check(int r, int c) {
		return r >= 0 && r < n && c >= 0 && c < n && !vst[r][c];
	}
	
	int n;
	vector<vector<bool> > vst;
	vector<vector<int> > matrix;
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	Solution sol;
	vector<vector<int> > matrix = sol.generateMatrix(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

