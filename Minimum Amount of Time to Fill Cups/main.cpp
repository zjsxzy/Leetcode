#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for (auto x: amount) {
            if (x > 0) pq.push(x);
        }
        int res = 0;
        while (!pq.empty()) {
            res++;
            if (pq.size() == 1) {
                int x = pq.top(); pq.pop();
                if (x > 1) pq.push(x - 1);
                // cout << x << endl;
            } else {
                int x = pq.top(); pq.pop();
                int y = pq.top(); pq.pop();
                if (x > 1) pq.push(x - 1);
                if (y > 1) pq.push(y - 1);
                // cout << x << ' ' << y << endl;
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

