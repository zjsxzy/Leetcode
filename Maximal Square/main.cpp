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

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        vector<vector<int> > dp(n, vector<int>(m, 0));
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // cout << i << " " << j << " " << matrix[i][j] << endl;
                if (i == 0 || j == 0) {
                    if (matrix[i][j] == '1') {
                        dp[i][j] = 1;
                    }
                } else {
                    if (matrix[i][j] == '1') {
                        dp[i][j] = get_min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
                        dp[i][j] = max(dp[i][j], 1);
                    }
                }
                res = max(res, dp[i][j]);
                // cout << i << " " << j << " " << dp[i][j] << endl;
            }
        }
        return res * res;
    }

    int get_min(int a, int b, int c) {
        int res = INT_MAX;
        res = min(res, a);
        res = min(res, b);
        res = min(res, c);
        return res;
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<char> > matrix(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            matrix[i][j] = temp + '0';
        }
    }
    Solution sol;
    int res = sol.maximalSquare(matrix);
    cout << res << endl;
	return 0;
}

