#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int res = 0, n = capacity.size();
        vector<int> vec;
        for (int i = 0; i < n; i++) {
            if (capacity[i] == rocks[i]) res++;
            else {
                vec.push_back(capacity[i] - rocks[i]);
            }
        }
        sort(vec.begin(), vec.end());
        int i = 0, m = vec.size(), x = additionalRocks;
        while (i < m && x) {
            // cout << vec[i] << " " << x << endl;
            if (vec[i] <= x) {
                res++;
                x -= vec[i];
                i++;
            } else {
                x = 0;
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
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

