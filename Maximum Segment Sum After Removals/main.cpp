#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct union_find{
    int N;
    vector<int> par, siz;
    vector<long long> sum;
    union_find(int n) : N(n){
        par.resize(N);
        siz.resize(N, 1);
        sum.resize(N);
        for(int i=0; i<N; i++) par[i] = i;
    }
    int root(int X){
        if(par[X] == X) return X;
        return par[X] = root(par[X]);
    }
    bool same(int X, int Y){
        return root(X) == root(Y);
    }
    void unite(int X, int Y){
        X = root(X);
        Y = root(Y);
        if(X == Y) return;
        if(siz[Y] < siz[X]) std::swap(X, Y);
        par[X] = Y;
        siz[Y] += siz[X];
        siz[X] = 0;
        sum[Y] += sum[X];
    }
};

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        vector<long long> res(n);
        union_find uf(n);
        for (int i = 0; i < n; i++) uf.sum[i] = nums[i];
        vector<int> vst(n);
        long long curr = 0;
        for (int i = n - 1; i > 0; i--) {
            int p = removeQueries[i];
            vst[p] = true;
            if (p > 0 && vst[p - 1]) {
                uf.unite(p - 1, p);
            }
            if (p < n - 1 && vst[p + 1]) {
                uf.unite(p, p + 1);
            }
            curr = max(curr, uf.sum[uf.root(p)]);
            res[i - 1] = curr;
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
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

