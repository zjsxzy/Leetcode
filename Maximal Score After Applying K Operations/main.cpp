#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (auto x: nums) pq.push(x);
        long long res = 0;
        for (int i = 0; i < k; i++) {
            auto t = pq.top(); pq.pop();
            res += t;
            if (t % 3 == 0) pq.push(t / 3);
            else pq.push(t / 3 + 1);
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

