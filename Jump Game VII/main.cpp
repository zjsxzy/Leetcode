#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

struct Fenwick{
    vector<int> tree;
    int n;
    Fenwick() {}
    Fenwick(int _n) {
        n = _n;
        tree.assign(n, 0);
    }
    void upd(int pos, int val) {
        for (; pos < n; pos |= pos + 1) {
            tree[pos] += val;
        }
    }
    int get(int r) {
        int ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += tree[r];
        }
        return ans;
    }
    int get(int l, int r) {
        if (l > r) return 0;
        if (l == 0) return get(r);
        return get(r) - get(l - 1);
    }
};

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n - 1] == '1') return false;
        Fenwick tree(n);
        tree.upd(0, 1);
        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                int l = max(0, i - maxJump), r = i - minJump;
                int t = tree.get(l, r);
                if (i == n - 1) {
                    if (t > 0) return true;
                    else return false;
                }
                if (t > 0) tree.upd(i, 1);
            }
        }
        return false;
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

