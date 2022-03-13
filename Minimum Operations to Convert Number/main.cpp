#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n = nums.size();
        vector<int> d(1005, -1);
        d[start] = 0;
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (int i = 0; i < n; i++) {
                int y = x + nums[i];
                if (y >= 0 && y <= 1000) {
                    if (d[y] == -1) {
                        d[y] = d[x] + 1;
                        q.push(y);
                    }
                } else if (y == goal) return d[x] + 1;
                y = x - nums[i];
                if (y >= 0 && y <= 1000) {
                    if (d[y] == -1) {
                        d[y] = d[x] + 1;
                        q.push(y);
                    }
                } else if (y == goal) return d[x] + 1;
                y = x ^ nums[i];
                if (y >= 0 && y <= 1000) {
                    if (d[y] == -1) {
                        d[y] = d[x] + 1;
                        q.push(y);
                    }
                } else if (y == goal) return d[x] + 1;
            }
        }

        if (goal >= 0 && goal <= 1000) return d[goal];
        else return -1;
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

