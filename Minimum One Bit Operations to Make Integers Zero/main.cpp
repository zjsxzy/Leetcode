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

    int minimumOneBitOperations(int n) {
        map<int, long long> f;
        for (int i = 0; i <= 30; i++) {
            f[i] = (1LL << (i + 1)) - 1;
        }
        int op = 1;
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            if (n & (1 << i)) {
                // cout << i << " " << f[i] << " " << op << endl;
                res += op * f[i];
                op *= -1;
            }
        }
        return res;
    }

};
int main() {
    Solution sol;
    cout << sol.minimumOneBitOperations(9) << endl;
    return 0;
}

