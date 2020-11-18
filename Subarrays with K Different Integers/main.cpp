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

const int maxn = 20005;
int cntl[maxn], cntr[maxn];

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size();
        int res = 0, diffl = 0, diffr = 0;
        memset(cntl, 0, sizeof(cntl));
        memset(cntr, 0, sizeof(cntr));
        for (int l = 0, rl = 0, rr = 0; l < n; l++) {
            while (rl < n && diffl < K) {
                if (cntl[A[rl]] == 0) {
                    diffl++;
                }
                cntl[A[rl]]++;
                rl++;
            }
            while (rr < n && diffr <= K) {
                if (cntr[A[rr]] == 0) {
                    diffr++;
                }
                cntr[A[rr]]++;
                rr++;
            }
            
            if (diffr == K + 1) {
                res += rr - rl;
            } else if (diffl == K) {
                res += n + 1 - rl;
            }
            // cout << l << " " << rl << " " << rr << " " << res << endl;
            
            cntl[A[l]]--;
            if (cntl[A[l]] == 0) diffl--;
            cntr[A[l]]--;
            if (cntr[A[l]] == 0) diffr--;
        }
        return res;
    }
};