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
    int numSquares(int n) {
        vector<int> sq;
        for (int i = 1; i * i <= n; i++) {
            sq.push_back(i * i);
        }
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
           for (int j = 0; j < sq.size(); j++) {
               if (i - sq[j] >= 0 && dp[i - sq[j]] != -1) {
                   dp[i] = dp[i] == -1 ? dp[i - sq[j]] + 1 : min(dp[i], dp[i - sq[j]] + 1);
               }
           }
        }
        return dp[n];
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
    Solution sol;
    cout << sol.numSquares(1) << endl;
	return 0;
}

