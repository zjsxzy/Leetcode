#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<long long> res(n);
        map<int, long long> sum, cnt;
        for (int i = 0; i < n; i++) {
            res[i] += cnt[arr[i]] * i - sum[arr[i]];
            sum[arr[i]] += i;
            cnt[arr[i]]++;
        }
        sum.clear(); cnt.clear();
        for (int i = n - 1; i >= 0; i--) {
            res[i] += sum[arr[i]] - cnt[arr[i]] * i;
            sum[arr[i]] += i;
            cnt[arr[i]]++;
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

