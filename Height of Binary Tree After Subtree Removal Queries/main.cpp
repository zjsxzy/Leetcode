#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct SegmentTree {
    using T = int;

    int N;
    vector<T> dat;

    T id = 0;
    T F(T &a, T &b) { return max(a, b); }

    SegmentTree(int n){
        N = 1;
        while(n > N) N = N << 1;
        dat = vector<T>(2 * N - 1, id);
    }

    SegmentTree(int n, vector<T> &v){
        N = 1;
        while(n > N) N = N << 1;
        dat = vector<T>(2 * N - 1, id);
        for(int i = 0; i < n; i++) dat[i + N - 1] = v[i];
        for(int i = N - 2; i >= 0; i--) dat[i] = F(dat[i * 2 + 1], dat[i * 2 + 2]);
    }

    SegmentTree(){}

    void update(int k, T a){
        k += N - 1;
        dat[k] = a;
        while(k > 0){
            k = (k - 1) / 2;
            dat[k] = F(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    void reset() { fill(dat.begin(), dat.end(), id); }

    T get(int a, int b, int k, int l, int r){
        if(r <= a || b <= l) return id;
        if(a <= l && r <= b) return dat[k];
        else{
            T vl = get(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = get(a, b, k * 2 + 2, (l + r) / 2, r);
            return F(vl, vr);
        }
    }
    T get(int a, int b) { return get(a, b, 0, 0, N); }

    T val(int k){ return dat[k + N - 1]; }
};

class Solution {
public:
    map<int, TreeNode*> idx;
    map<TreeNode*, int> left, right;
    vector<int> dep;
    int cnt, n;
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        cnt = 0;
        dfs(root, 0);
        n = cnt;
        SegmentTree tree(n, dep);
        // for (auto d: dep) cout << d << ' ';
        // cout << endl;
        vector<int> ans;
        for (auto q: queries) {
            TreeNode* p = idx[q];
            int L = left[p], R = right[p];
            // cout << q << ' ' << L << ' ' << R << endl;
            int curr = max(tree.get(0, L), tree.get(R, n));
            ans.push_back(curr);
        }
        return ans;
    }
    void dfs(TreeNode* p, int depth) {
        if (p == NULL) return;
        idx[p->val] = p;
        left[p] = cnt++;
        dep.push_back(depth);
        dfs(p->left, depth + 1);
        dfs(p->right, depth + 1);
        right[p] = cnt;
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

