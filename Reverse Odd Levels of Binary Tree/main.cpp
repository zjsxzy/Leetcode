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
class Solution {
public:
    map<int, vector<TreeNode*>> tree;
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root, 0);
        for (auto [k, v]: tree) {
            if (k & 1) {
                reverse(tree[k].begin(), tree[k].end());
            }
            if (tree.find(k - 1) != tree.end()) {
                int n = v.size();
                for (int i = 0; i < n; i++) {
                    tree[k][i]->left = tree[k - 1][2 * i];
                    tree[k][i]->right = tree[k - 1][2 * i + 1];
                }
            }
        }
        return root;
    }

    void dfs(TreeNode* p, int level) {
        if (!p) return;
        tree[-level].push_back(p);
        dfs(p->left, level + 1);
        dfs(p->right,level + 1);
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

