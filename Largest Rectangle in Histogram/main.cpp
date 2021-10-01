#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            left[i] = (stk.empty() ? -1 : stk.top());
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            right[i] = (stk.empty() ? n : stk.top());
            stk.push(i);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, heights[i] * (right[i] - left[i] - 1));
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

