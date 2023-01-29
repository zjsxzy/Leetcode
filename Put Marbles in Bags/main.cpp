#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> a;
        for (int i = 1; i < n; i++) {
            a.push_back(weights[i] + weights[i - 1]);
        }
        sort(a.begin(), a.end());
        long long x = 0, y = 0;
        for (int i = 0; i < k - 1; i++) {
            x += a[i];
        }
        reverse(a.begin(), a.end());
        for (int i = 0; i < k - 1; i++) {
            y += a[i];
        }
        return y - x;
    }
};

void solve() {
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

