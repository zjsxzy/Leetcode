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

const int maxn = 1024;
bool f[maxn], g[maxn];
int sum[maxn];

class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        map<int, int> cnt;
        for (auto x : nums) {
            cnt[x]++;
        }
        vector<int> vec;
        for (auto x : cnt) {
            vec.push_back(x.second);
        }

        int n = vec.size(), m = quantity.size();
        for (int j = 0; j < (1 << m); j++) {
            sum[j] = 0;
            for (int i = 0; i < m; i++) {
                if (j & (1 << i)) {
                    sum[j] += quantity[i];
                }
            }
        }

        memset(f, false, sizeof(f));
        f[0] = true;
        for (int i = 0; i < n; i++) {
            memset(g, false, sizeof(g));
            g[0] = true;
            for (int j = 0; j < (1 << m); j++) {
                if (f[j]) {
                    for (int k = 1; k < (1 << m); k++) {
                        int s = (j ^ k) & k; // new quantities
                        if (sum[s] <= vec[i]) {
                            g[k] = true;
                        }
                    }
                }
            }
            for (int j = 0; j < (1 << m); j++) {
                f[j] = g[j];
            }
        }
        return f[(1 << m) - 1];
    }
};

int main() {
}
