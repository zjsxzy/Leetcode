#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int res;
    map<TreeNode*, int> sum, sz;
    int averageOfSubtree(TreeNode* root) {
        res = 0;
        sum.clear();
        sz.clear();
        dfs(root);
        return res;
    }

    void dfs(TreeNode* p) {
        if (p->left != nullptr) {
            dfs(p->left);
            sum[p] += sum[p->left];
            sz[p] += sz[p->left];
        }
        if (p->right != nullptr) {
            dfs(p->right);
            sum[p] += sum[p->right];
            sz[p] += sz[p->right];
        }
        sum[p] += p->val;
        sz[p]++;
        // cout << p->val << " " << sum[p] << " " << sz[p] << endl;
        if (sum[p] / sz[p] == p->val) {
            res++;
        }
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

