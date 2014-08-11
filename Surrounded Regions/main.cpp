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
 * Description: Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 *
 * Solution: BFS
 *
 */
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
class Solution {
public:
    void solve(vector<vector<char> > &board) {
		n = board.size();
		if (n == 0) return;
		m = board[0].size();
		this->board = board;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (this->board[i][j] == 'O')
					bfs(i, j);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (this->board[i][j] == '#')
					this->board[i][j] = 'O';
		board = this->board;
    }

	void bfs(int x, int y) {
		vector<pair<int, int> > pos;
		queue<pair<int, int> > q;
		q.push(MP(x, y));
		bool capture = true;
		while (!q.empty()) {
			pair<int, int> cur = q.front(); q.pop();
			pos.PB(cur);
			board[cur.first][cur.second] = '#';
			for (int k = 0; k < 4; k++) {
				int xx = cur.first + dx[k], yy = cur.second + dy[k];
				if (inside(xx, yy)) {
					if (board[xx][yy] == 'O') {
						q.push(MP(xx, yy));
						board[xx][yy] = '#';
					}
				} else {
					capture = false;
				}
			}
		}
		if (capture) {
			FOREACH(it, pos) {
				board[it->first][it->second] = 'X';
			}
		}
	}

	bool inside(int x, int y) {
		return x >= 0 && x < n && y >= 0 && y < m;
	}

	int n, m;
	vector<vector<char> > board;
};
int N = 3;
int main() {
	string a[3] = {"OOO", "OXO", "OOO"};
	//string a[4] = {"XXXX", "XOOX", "XXOX", "XOXX"};
	vector<vector<char> > board(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i].PB(a[i][j]);
		}
	}
	Solution sol;
	sol.solve(board);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
	return 0;
}

