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
    int pseudoPalindromicPaths (TreeNode* root) {
        if (root == NULL) return 0;
        int res = 0;
        function<void(TreeNode* p, int mask)> dfs = [&](TreeNode* p, int mask) {
            mask ^= 1 << (p->val);
            if (p->left == NULL && p->right == NULL) {
                if (mask == 0 || (mask & (mask - 1)) == 0) {
                    res++;
                    return;
                }
            }
            if (p->left != NULL) dfs(p->left, mask);
            if (p->right != NULL) dfs(p->right, mask);
        };
        dfs(root, 0);
        return res;
    }
};

void solve() {
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
       solve();
    }
    return 0;
}

