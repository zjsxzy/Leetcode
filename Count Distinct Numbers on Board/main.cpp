#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int distinctIntegers(int n) {
        set<int> st;
        queue<int> q;
        q.push(n);
        st.insert(n);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (int i = 1; i <= n; i++) {
                if (x % i == 1 && !st.count(i)) {
                    st.insert(i);
                    q.push(i);
                }
            }
        }
        return st.size();
    }
};

void solve() {
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

