#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> t(n);
        for (int i = 0; i < n; i++) {
            if (dist[i] % speed[i] == 0) t[i] = dist[i] / speed[i];
            else t[i] = dist[i] / speed[i] + 1;
        }
        sort(t.begin(), t.end());
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (i < t[i]) res++;
            else break;
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

