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
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 *
 * Soution:
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
    bool hasPathSum(TreeNode *root, int sum) {
		this->sum = sum;
		ret = false;
		if (root == NULL) return false;
		dfs(root, 0);
		return ret;
    }
	
	void dfs(TreeNode *p, int cur) {
		cur += p->val;
		bool leaf = true;
		if (p->left != NULL) {
			leaf = false;
			dfs(p->left, cur);
		}
		if (p->right != NULL) {
			leaf = false;
			dfs(p->right, cur);
		}
		if (leaf && cur == sum) {
			ret = true;
		}
	}
	
	bool ret;
	int sum;
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	return 0;
}

