#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;
class Solution {
public:
    int totalStrength(vector<int>& strength) {
        int n = strength.size();
        vector<long long> a(n + 1);
        for (int i = 0; i < n; i++) {
            a[i + 1] = strength[i];
        }
        vector<int> left(n + 1), right(n + 1);
        for (int i = 1; i <= n; i++) {
            left[i] = i - 1;
            while (left[i] >= 1 && a[left[i]] > a[i]) {
                left[i] = left[left[i]];
            }
        }
        for (int i = n; i >= 1; i--) {
            right[i] = i + 1;
            while (right[i] <= n && a[right[i]] >= a[i]) {
                right[i] = right[right[i]];
            }
        }

        vector<long long> s(n + 1);
        for (int i = 1; i <= n; i++) {
            s[i] = (s[i - 1] + a[i]) % mod;
        }
        vector<long long> sum(n + 1);
        for (int i = 1; i <= n; i++) {
            sum[i] = (sum[i - 1] + s[i]) % mod;
        }
        auto fsum = [&](int l, int r) {
            if (l <= 0) return sum[r];
            return (sum[r] - sum[l - 1] + mod) % mod;
        };

        long long res = 0;
        for (int i = 1; i <= n; i++) {
            long long sl = fsum(left[i], i - 1);
            long long sr = fsum(i, right[i] - 1);
            res += 1ll * a[i] * (sr * (i - left[i]) % mod - sl * (right[i] - i) % mod + mod) % mod;
            res %= mod;
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

