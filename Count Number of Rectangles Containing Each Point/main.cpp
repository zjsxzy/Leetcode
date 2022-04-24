#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        int m = rectangles.size(), n = points.size();
        vector<pair<pair<int, int>, int>> vec;
        for (auto& r: rectangles) {
            vec.push_back({{r[0], r[1]}, n + 1});
        }
        for (int i = 0; i < n; i++) {
            vec.push_back({{points[i][0], points[i][1]}, i});
        }
        sort(vec.rbegin(), vec.rend());
        vector<int> res(n);
        multiset<int> y;
        for (auto& v: vec) {
            if (v.second == n + 1) {
                y.insert(v.first.second);
            } else {
                int sz = y.size();
                int t = distance(y.begin(), y.lower_bound(v.first.second));
                res[v.second] = sz - t;
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

