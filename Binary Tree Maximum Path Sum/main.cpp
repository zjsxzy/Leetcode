#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

/*
 * Description:
 * Given a binary tree, find the maximum path sum. The path may start and end at any node in the tree.
 *
 * Solution:
 * DFS.
 *
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int maxPathSum(TreeNode *root) {
		if (root == NULL) return 0;
		maxPath = INT_MIN;
		dfs(root);
		return maxPath;
    }
	
	int dfs(TreeNode *p) {
		int vL = 0, vR = 0;
		if (p->left != NULL)
			vL = dfs(p->left);
		if (p->right != NULL)
			vR = dfs(p->right);
		maxPath = max(maxPath, max(vL, 0) + max(vR, 0) + p->val);
		return max(max(vL, 0), max(vR, 0)) + p->val;
	}
	
	int maxPath;
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	return 0;
}

