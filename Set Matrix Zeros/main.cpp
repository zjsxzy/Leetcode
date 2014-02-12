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
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 *
 * Solution:
 * Brute force
 */
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
		vector<int> row, col;
		int n = matrix.size(), m = matrix[0].size();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (matrix[i][j] == 0) {
					row.push_back(i); col.push_back(j);
				}
		for (int i = 0; i < row.size(); i++) {
			for (int j = 0; j < m; j++) {
				matrix[row[i]][j] = 0;
			}
		}
		for (int j = 0; j < col.size(); j++) {
			for (int i = 0; i < n; i++) {
				matrix[i][col[j]] = 0;
			}
		}
    }
};

int main() {
}

