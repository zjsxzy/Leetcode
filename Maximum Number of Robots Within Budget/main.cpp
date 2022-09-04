#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct SegmentTree {
    using T = int;

    int N;
    vector<T> dat;

    T id = 0;
    T F(T &a, T &b) { return max(a, b); }

    SegmentTree(int n){
        N = 1;
        while(n > N) N = N << 1;
        dat = vector<T>(2 * N - 1, id);
    }

    SegmentTree(int n, vector<T> &v){
        N = 1;
        while(n > N) N = N << 1;
        dat = vector<T>(2 * N - 1, id);
        for(int i = 0; i < n; i++) dat[i + N - 1] = v[i];
        for(int i = N - 2; i >= 0; i--) dat[i] = F(dat[i * 2 + 1], dat[i * 2 + 2]);
    }

    SegmentTree(){}

    void update(int k, T a){
        k += N - 1;
        dat[k] = a;
        while(k > 0){
            k = (k - 1) / 2;
            dat[k] = F(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    void reset() { fill(dat.begin(), dat.end(), id); }

    T get(int a, int b, int k, int l, int r){
        if(r <= a || b <= l) return id;
        if(a <= l && r <= b) return dat[k];
        else{
            T vl = get(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = get(a, b, k * 2 + 2, (l + r) / 2, r);
            return F(vl, vr);
        }
    }
    T get(int a, int b) { return get(a, b, 0, 0, N); }

    T val(int k){ return dat[k + N - 1]; }
};

class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        vector<long long> sum(n);
        sum[0] = runningCosts[0];
        for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + runningCosts[i];
        auto range_sum = [&](int l, int r) {
            if (l == 0) return sum[r];
            return sum[r] - sum[l - 1];
        };

        SegmentTree tree(n, chargeTimes);

        auto check = [&](int k) {
            if (k == 0) return true;
            for (int i = 0; i < n; i++) {
                int j = i + k - 1;
                if (j >= n) continue;
                long long t = budget - range_sum(i, j) * k;
                if (tree.get(i, j + 1) <= t) return true;
            }
            return false;
        };

        int lo = 0, hi = n, res = 0;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (check(mid)) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
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
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

