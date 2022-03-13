#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        int n = beans.size();
        long long res = (1LL << 60), sum = 0;
        vector<long long> s(n);
        s[n - 1] = beans[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            s[i] = s[i + 1] + beans[i];
        }
        for (int i = 0; i < n; i++) {
            long long t = sum;
            long long m = n - (i + 1);
            if (i < n - 1) {
                t += s[i + 1] - beans[i] * m;
            }
            // cout << i << " " << beans[i] << " " << t << endl;
            res = min(res, t);
            sum += beans[i];
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

