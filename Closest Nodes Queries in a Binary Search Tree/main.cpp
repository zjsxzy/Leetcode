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
    set<int> val;
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        val.clear();
        dfs(root);
        int n = queries.size();
        // for (auto x: val) cout << x << endl;
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            auto it = val.lower_bound(queries[i]);
            int x, y;
            if (it == val.end()) it--;
             // cout << i << ' ' << queries[i] << ' ' << *it << endl;
            if (it != val.end() && *it > queries[i]) {
                if (it == val.begin()) x = -1;
                else {
                    it--;
                    x = *it;
                }
            } else {
                x = *it;
            }

            it = val.lower_bound(queries[i]);
            if (it != val.end()) y = *it;
            else y = -1;

            ans.push_back({x, y});
        }
        return ans;
    }

    void dfs(TreeNode* p) {
        if (p == NULL) return;
        val.insert(p->val);
        dfs(p->left);
        dfs(p->right);
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

