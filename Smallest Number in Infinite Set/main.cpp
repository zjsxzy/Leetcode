#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class SmallestInfiniteSet {
public:
    set<int> st;
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; i++) st.insert(i);
    }

    int popSmallest() {
        auto x = st.begin();
        int res = *x;
        st.erase(x);
        return res;
    }

    void addBack(int num) {
        if (st.find(num) == st.end()) {
            st.insert(num);
        }
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

