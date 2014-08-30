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
 * Given a binary tree, return the postorder traversal of its nodes' values.
 *
 * Solution:
 * Using a stack to implement recursion.
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
    vector<int> postorderTraversal(TreeNode *root) {
		vector<int> ret;
		stack<TreeNode*> nstack;
		if (root != NULL) nstack.push(root);
		TreeNode* prev = NULL;
		while (!nstack.empty()) {
			TreeNode* curr = nstack.top();
			if (prev == NULL || prev->left == curr || prev->right == curr) {
				if (curr->left != NULL) {
					nstack.push(curr->left);
				} else if (curr->right != NULL) {
					nstack.push(curr->right);
				} else {
					nstack.pop();
					ret.push_back(curr->val);
				}
			} else if (curr->left == prev) {
				if (curr->right != NULL) {
					nstack.push(curr->right);
				} else {
					nstack.pop();
					ret.push_back(curr->val);
				}
			} else if (curr->right == prev) {
				nstack.pop();
				ret.push_back(curr->val);
			}
			prev = curr;
		}    
		return ret;
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	return 0;
}

