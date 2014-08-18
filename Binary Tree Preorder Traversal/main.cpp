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
 * Description: Given a binary tree, return the preorder traversal of its nodes' values.
 *
 * Solution: Using stack to implement recursion.
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
    vector<int> preorderTraversal(TreeNode *root) {
		vector<int> ret;
		stack<TreeNode*> nstack;
		if (root != NULL) nstack.push(root);
		while (!nstack.empty()) {
			TreeNode* p = nstack.top(); nstack.pop();
			ret.push_back(p->val);
			if (p->right != NULL)
				nstack.push(p->right);
			if (p->left != NULL)
				nstack.push(p->left);
		}
		return ret;
    }
};
int main() {
}

