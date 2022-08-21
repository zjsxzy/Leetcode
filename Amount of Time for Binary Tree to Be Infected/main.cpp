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
    map<int, vector<int>> adj;
    map<int, int> d1, d2;
    int amountOfTime(TreeNode* root, int start) {
        adj.clear();
        build(root);
        d1.clear();
        d2.clear();
        dfs(start, -1);
        return max(d1[start], d2[start]);
    }

    void build(TreeNode* p) {
        int u = p->val;
        if (p->left) {
            int v = p->left->val;
            adj[u].push_back(v);
            adj[v].push_back(u);
            build(p->left);
        }
        if (p->right) {
            int v = p->right->val;
            adj[u].push_back(v);
            adj[v].push_back(u);
            build(p->right);
        }
    }

    void dfs(int u, int fa) {
        d1[u] = d2[u] = 0;
        for (int v : adj[u]) {
            if (v == fa) continue;
            dfs(v, u);
            int t = d1[v] + 1;
            if (t > d1[u])
                d2[u] = d1[u], d1[u] = t;
            else if (t > d2[u])
                d2[u] = t;
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

