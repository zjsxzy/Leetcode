#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n = energy.size();
        int res = 0, e = 0;
        for (auto x: energy) e += x;
        res += max(0, e - initialEnergy + 1);
        int mx = 0, curr = initialExperience;
        // cout << res << endl;
        for (auto x: experience) {
            if (curr <= x) {
                mx = max(mx, x - curr + 1);
            }
            curr += x;
        }
        // cout << mx << endl;
        res += max(0, mx);
        return res;
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

