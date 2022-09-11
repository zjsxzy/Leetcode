#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
        });
        multiset<int> st;
        for (auto i: intervals) {
            if (!st.empty()) {
                auto x = st.begin();
                if (*x < i[0]) {
                    st.erase(x);
                }

            }
            st.insert(i[1]);
        }
        return (int)st.size();
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

