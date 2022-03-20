#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 100005;
string S;
struct SegTree {
	int mx[MAXN << 2], pref[MAXN << 2], suff[MAXN << 2];
	int lson(int rt) {return rt << 1;}
	int rson(int rt) {return rt << 1 | 1;}
	void pushUp(int l, int r, int rt) {
		int mid = (l + r) >> 1;
        if (pref[lson(rt)] == mid - l + 1 && S[mid] == S[mid + 1]) pref[rt] = pref[lson(rt)] + pref[rson(rt)];
        else pref[rt] = pref[lson(rt)];
        if (suff[rson(rt)] == r - mid && S[mid] == S[mid + 1]) suff[rt] = suff[lson(rt)] + suff[rson(rt)];
        else suff[rt] = suff[rson(rt)];
        mx[rt] = max(mx[lson(rt)], mx[rson(rt)]);
        if (S[mid] == S[mid + 1]) mx[rt] = max(mx[rt], suff[lson(rt)] + pref[rson(rt)]);
	}
	void build(int l, int r, int rt) {
		if (l == r) {
			mx[rt] = pref[rt] = suff[rt] = 1;
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, lson(rt));
		build(mid + 1, r, rson(rt));
		pushUp(l, r, rt);
	}
    void update(int p, int l, int r, int rt) {
        if (l == r) return;
        int mid = (l + r) >> 1;
        if (p <= mid) update(p, l, mid, lson(rt));
        else update(p, mid + 1, r, rson(rt));
        pushUp(l, r, rt);
    }
}tree;

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        S = " " + s;
        int n = s.size(), k = queryIndices.size();
        tree.build(1, n, 1);
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            S[queryIndices[i] + 1] = queryCharacters[i];
            tree.update(queryIndices[i] + 1, 1, n, 1);
            ans[i] = tree.mx[1];
        }
        return ans;
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

