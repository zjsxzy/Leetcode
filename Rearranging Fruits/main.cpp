#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> cnt, A, B;
        for (auto x: basket1) {
            cnt[x]++;
            A[x]++;
        }
        for (auto x: basket2) {
            cnt[x]++;
            B[x]++;
        }
        for (auto [k, v]: cnt) {
            if (v & 1) return -1;
        }
        vector<int> a, b;
        for (auto [k, v]: A) {
            while (v > cnt[k] / 2) {
                v--;
                a.push_back(k);
            }
        }
        for (auto [k, v]: B) {
            while (v > cnt[k] / 2) {
                v--;
                b.push_back(k);
            }
        }
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        int mn = cnt.begin()->first;
        int m = a.size();
        long long res = 0;
        for (int i = 0; i < m; i++) {
            res += min(min(a[i], b[i]), 2 * mn);
        }
        return res;
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

