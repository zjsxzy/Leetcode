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
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> f(n, INT_MAX), g(n, INT_MAX);
        f[0] = 0; g[0] = 1;
        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                f[i] = min(f[i], f[i - 1]);
                g[i] = min(g[i], g[i - 1] + 1);
            }
            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
                f[i] = min(f[i], g[i - 1]);
                g[i] = min(g[i], f[i - 1] + 1);
            }
        }
        return min(f[n - 1], g[n - 1]);
    }
};

int main() {
}

