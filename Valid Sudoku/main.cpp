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
 * Descrition:
 * Determine if a Sudoku is valid.
 *
 * Solution:
 * Brute force
 */
class Solution {
public:
	bool row[9][9], col[9][9], grid[9][9];
    bool isValidSudoku(vector<vector<char> > &board) {
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(grid, 0, sizeof(grid));
		for (int r = 0; r < 9; r++) {
			for (int c = 0; c < 9; c++) {
				if (board[r][c] != '.') {
					int g = (r / 3) * 3 + (c / 3);
					int x = board[r][c] - '1';
					if (row[r][x] || col[c][x] || grid[g][x]) return false;
					row[r][x] = col[c][x] = grid[g][x] = true;
				}
			}
		}
		return true;
    }
};
int main() {
}

