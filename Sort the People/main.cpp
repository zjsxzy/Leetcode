#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> vec;
        int n = names.size();
        for (int i = 0; i < n; i++) {
            vec.push_back({-heights[i], names[i]});
        }
        sort(vec.begin(), vec.end());
        vector<string> ans;
        for (auto x: vec) ans.push_back(x.second);
        return ans;
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

