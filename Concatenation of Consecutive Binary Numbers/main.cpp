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
typedef long long LL;

const int MOD = 1000000007;
int bits[50];
class Solution {
public:
    int concatenatedBinary(int n) {
        int res = 1;
        for (int i = 2; i <= n; i++) {
            int x = i;
            int l = 0;
            while (x) {
                bits[l] = x & 1;
                l++;
                x >>= 1;
            }
            for (int j = 0; j < l; j++) {
                res = (res * 2) % MOD;
                res = (res + bits[l - j - 1]) % MOD;
            }
        }
        return res;
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

