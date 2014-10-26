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
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
 *
 * Solution:
 * DP.
 *
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
		if (matrix.empty()) return 0;
		int n = matrix.size(), m = matrix[0].size();
		vector<int> H(m, 0), L(m, 0), R(m, m);
		int area = 0;
		for (int i = 0; i < n; i++) {
			int left = 0, right = m;
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] == '1') {
					H[j]++;
					L[j] = max(L[j], left);
				} else {
					left = j + 1;
					H[j] = 0; L[j] = 0; R[j] = m;
				}
			}
			for (int j = m - 1; j >= 0; j--) {
				if (matrix[i][j] == '1') {
					R[j] = min(R[j], right);
					area = max(area, H[j] * (R[j] - L[j]));
				} else {
					right = j;
				}
			}
		}
		return area;
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	vector<vector<char> > matrix(n);
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			matrix[i].push_back(str[j]);
		}
	}
	Solution sol;
	cout << sol.maximalRectangle(matrix) << endl;
	return 0;
}

