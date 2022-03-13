#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        map<int, vector<int>> mp;
        for (int i = 0; i < tasks.size(); i++) {
            mp[tasks[i][0]].push_back(i);
        }
        int now = 0;
        for (auto [t, v] : mp) {
            while (now < t && !pq.empty()) {
                auto [duration, idx] = pq.top();
                pq.pop();
                now += duration;
                res.push_back(idx);
            }
            if (now < t && pq.empty()) {
                now = t;
            }
            if (now >= t) {
                for (int i : v) {
                    pq.push({tasks[i][1], i});
                }
            }
        }

        while (!pq.empty()) {
            auto [duration, idx] = pq.top();
            pq.pop();
            res.push_back(idx);
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

