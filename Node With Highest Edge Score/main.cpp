#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> sum(n);
        for (int i = 0; i < n; i++) {
            sum[edges[i]] += i;
        }
        set<pair<long long, int>> st;
        for (int i = 0; i < n; i++) {
            st.insert({-sum[i], i});
        }
        auto res = st.begin();
        return res->second;
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

