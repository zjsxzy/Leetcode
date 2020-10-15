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

const int MOD = 1000000007;
const int MAXN = 1005;
int dp[MAXN][4];
class Solution {
    public:
    int numTilings(int N) {
        memset(dp, 0, sizeof(dp));
        dp[1][0b00] = 1;
        dp[1][0b11] = 1;
        for (int i = 2; i <= N; i++) {
            dp[i][0b00] = dp[i - 1][0b11];
            dp[i][0b01] = (dp[i - 1][0b00] + dp[i - 1][0b10]) % MOD;
            dp[i][0b10] = (dp[i - 1][0b00] + dp[i - 1][0b01]) % MOD;
            dp[i][0b11] = (((dp[i - 1][0b10] + dp[i - 1][0b01]) % MOD + (dp[i - 1][0b00] + dp[i - 1][0b11]) % MOD)) % MOD;
        }
        return dp[N][0b11];
    }
};

int main() {
    Solution sol;
    cout << sol.numTilings(3) << endl;
    return 0;
}

