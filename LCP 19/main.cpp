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
    int minimumOperations(string leaves) {
        /*
         * s[i]: how many red leavs in 1..i
         * result:
         * first part: i-s[i],
         * second part: s[j]-s[i]
         * third part: n-j-(s[n]-s[j])
         * result = n+i-2s[i]-s[n]+2s[j]-j
         * enumerate i, find j that minimizes results
         * f[j]: min_{k=j,...n}(2s[k]-k)
         * results = n+i-2s[i]-s[n]+f[i+1]
         */
        int n = leavs.size();
        vector<int> s(n+1), f(n+1);
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = s[i-1] + (leaves[i-1] == 'r');
        }
        f[n] = INT_MAX;
        for (int j = n - 1; j > 0; j--) {
            int temp = 2 * s[j] - j;
            f[j] = min(f[j + 1], temp);
        }
        int res = INT_MAX;
        for (int i = 1; i < n - 1; i++) {
            int temp = n + i - 2 * s[i] - s[n] + f[i + 1];
            if (temp < res) res = temp;
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;
    cout << sol.minimumOperations(s) << endl;
    return 0;
}

