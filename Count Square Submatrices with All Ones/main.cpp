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

int get_min(int a, int b, int c) {
    int res = a;
    if (b < res) res = b;
    if (c < res) res = c;
    return res;
}

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        vector<vector<int> > dp(n, vector<int>(m, 0));
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = matrix[i][j];
                    } else {
                        dp[i][j] = get_min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
                    }
                    res += dp[i][j];
                }
            }
        }
        return res;
    }
};

int main() {
}

