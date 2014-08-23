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
 * Two elements of a binary search tree (BST) are swapped by mistake. Recover the tree without changing its structure.
 *
 * Solution:
 * In-order traversal dfs.
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

    void recoverTree(TreeNode *root) {
        last = ansF = ansS = NULL;
		dfs(root);
		if (ansF != NULL && ansS != NULL) {
			int temp = ansF->val;
			ansF->val = ansS->val;
			ansS->val = temp;
		}
    }
	
	void dfs(TreeNode *p) {
		if (p == NULL) return;
		dfs(p->left);
		if (last != NULL && p->val < last->val) {
			if (ansF == NULL) {
				ansF = last;
				ansS = p;
			} else {
				ansS = p;
			}
		}
		last = p;
		dfs(p->right);
	}
	
	TreeNode *last;
	TreeNode *ansF, *ansS;
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	return 0;
}

