#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class CountIntervals {
public:
    int res;
    set<pair<int, int>> st;
    CountIntervals() {
        res = 0;
        st.clear();
        st.insert({0, 0});
        st.insert({(int)1e9 + 1, (int)1e9 + 1});
    }

    void add(int left, int right) {
        int L = left, R = right;
        // cout << left << " " << right << endl;
        auto it = st.lower_bound({right + 1, -2e9});
        it--;
        while (true) {
            // cout << it->first << " " << it->second << endl;
            if (it->second < left) break;
            L = min(L, it->first);
            R = max(R, it->second);
            res -= it->second - it->first + 1;
            // st.erase(it--);
            auto p = *it;
            it--;
            st.erase(p);
        }
        // cout << endl;
        res += R - L + 1;
        st.insert({L, R});
    }

    int count() {
        return res;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

