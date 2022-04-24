#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;


class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<pair<int, int>> vec;
        for (auto& f: flowers) {
            vec.push_back({f[0], -1});
            vec.push_back({f[1] + 1, -2});
        }
        int n = persons.size();
        for (int i = 0; i < n; i++) {
            vec.push_back({persons[i], i});
        }
        vector<int> res(n);
        sort(vec.begin(), vec.end());
        int curr = 0;
        for (auto& v: vec) {
            if (v.second == -2) curr--;
            else if (v.second == -1) curr++;
            else {
                res[v.second] = curr;
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
    solve();
    return 0;
}

