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
 * Given two binary trees, write a function to check if they are equal or not.
 *
 * Solution:
 * DFS
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
		if (p == NULL && q == NULL) return true;
		else if (p == NULL || q == NULL) return false;
        same = true;
		dfs(p, q);
		return same;
    }
	
	void dfs(TreeNode *p, TreeNode *q) {
		if (!same) return;
		if (p->val != q->val) {
			same = false;
			return;
		}
		
		if (p->left != NULL && q->left != NULL) {
			dfs(p->left, q->left);
		} else if ((p->left == NULL && q->left != NULL) || (p->left != NULL && q->left == NULL)) {
			same = false;
			return;
		}
		
		if (p->right != NULL && q->right != NULL) {
			dfs(p->right, q->right);
		} else if ((p->right == NULL && q->right != NULL) || (p->right != NULL && q->right == NULL)) {
			same = false;
			return;
		}
	}
	
	bool same;
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	return 0;
}

