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
 * Description:Given a binary tree, flatten it to a linked list in-place.
 *
 * Solution: pre-order traversal.
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
    void flatten(TreeNode *root) {
		if (root == NULL) return;
		traverse(root);
    }
	TreeNode* traverse(TreeNode *p) {
		if (p->left == NULL && p->right == NULL)
			return p;
		if (p->right == NULL) {
			p->right = p->left;
			p->left = NULL;
		}
		if (p->left == NULL) {
			return traverse(p->right);
		}
		TreeNode *eL = traverse(p->left);
		TreeNode *eR = traverse(p->right);
		eL->right = p->right;
		p->right = p->left;
		p->left = NULL;
		return eR;
	}
};
int main() {
}

