#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Allocator {
public:
    vector<int> idx;
    set<int> st;
    int N;
    Allocator(int n) {
        N = n;
        idx.resize(n);
        st.clear();
        st.insert(n);
    }

    int allocate(int size, int mID) {
        int curr = -1, find = -1;
        for (auto x: st) {
            if (x - curr - 1 >= size) {
                find = curr + 1;
                break;
            }
            curr = x;
        }
        if (find == -1) return find;
        for (int i = find; i < find + size; i++) {
            idx[i] = mID;
            st.insert(i);
        }
        return find;
    }

    int free(int mID) {
        int res = 0;
        for (int i = 0; i < N; i++) {
            if (idx[i] == mID) {
                idx[i] = 0, res++;
                st.erase(i);
            }
        }
        return res;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
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

