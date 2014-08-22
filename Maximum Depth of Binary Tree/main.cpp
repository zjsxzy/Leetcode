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
 * Given a binary tree, find its maximum depth.
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
    int maxDepth(TreeNode *root) {
		if (root == NULL) return 0;
		maxDep = 0;
		dfs(root, 0);
		return maxDep;
    }
	
	void dfs(TreeNode *p, int dep) {
		bool leaf = true;
		if (p->left != NULL) {
			leaf = false;
			dfs(p->left, dep + 1);
		}
		if (p->right != NULL) {
			leaf = false;
			dfs(p->right, dep + 1);
		}
		if (leaf) maxDep = max(maxDep, dep + 1);
	}
	
	int maxDep;
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	return 0;
}

