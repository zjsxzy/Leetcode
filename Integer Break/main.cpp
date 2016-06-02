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

class Solution {
public:
    vector<int> dp;
    int f(int n) {
        if (dp[n] != 0) return dp[n];
        if (n <= 2) return dp[n] = 1;
        int res = 0;
        for (int i = 2; i < n; i++) {
            int temp = i * (n - i);
            res = max(res, temp);
            temp = f(i) * (n - i);
            res = max(res, temp);
            temp = f(i) * f(n - i);
            res = max(res, temp);
        }
        return dp[n] = res;
    }

    int integerBreak(int n) {
        dp.resize(n + 1);
        return f(n);
    }
};
int main() {
    Solution sol;
    cout << sol.integerBreak(10) << endl;
    return 0;
}

