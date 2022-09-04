#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < m; i++) {
            vec.push_back({meetings[i][0], i});
        }
        sort(vec.begin(), vec.end());

        vector<int> cnt(n);
        set<pair<long long, int>> use;
        set<int> unuse;
        for (int i = 0; i < n; i++) unuse.insert(i);

        for (auto v: vec) {
            int idx = v.second;
            while (!use.empty() && use.begin()->first <= v.first) {
                unuse.insert(use.begin()->second);
                use.erase(use.begin());
            }
            if (!unuse.empty()) {
                auto x = unuse.begin();
                int i = *x;
                cnt[i]++;
                use.insert({meetings[idx][1], i});
                unuse.erase(x);
            } else {
                auto x = use.begin();
                long long ti = x->first;
                int i = x->second;
                cnt[i]++;
                use.insert({ti + meetings[idx][1] - meetings[idx][0], i});
                use.erase(x);
            }
        }

        int p = 0;
        for (int i = 1; i < n; i++) {
            if (cnt[i] > cnt[p]) p = i;
        }
        return p;
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

