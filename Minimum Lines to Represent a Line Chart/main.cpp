#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct Point {
    long long x, y;
    Point() {}
    Point(long long x_, long long y_) : x(x_), y(y_) {}
};
class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        vector<Point> ps;
        for (auto s: stockPrices) {
            ps.emplace_back(s[0], s[1]);
        }
        sort(ps.begin(), ps.end(), [&](const Point& a, const Point& b) {
            return a.x < b.x;
        });
        int n = ps.size();
        if (n == 1) return 0;
        if (n == 2) return 1;
        int res = 1;
        Point o = ps[0], a = ps[1];
        for (int i = 2; i < n; i++) {
            Point b = ps[i];
            if (cross(o, a, b) != 0) {
                // cout << i << endl;
                res++;
                o = ps[i - 1];
                a = ps[i];
            }
        }
        return res;
    }
    long long cross(const Point & o, const Point & a, const Point & b) {
	    return (a.x-o.x)*(b.y-o.y) - (b.x-o.x)*(a.y-o.y);
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

