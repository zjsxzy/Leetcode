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
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Solution:
 * Recusive construction.
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int N, nxt;
	map<int, int> pos;
	vector<int> inorder, preorder;

	TreeNode *construct(int start, int end) {
		if (end - start == 0) return NULL;
		int cur = preorder[nxt++];
		TreeNode *root = new TreeNode(cur);
		int mid = pos[cur];
		root->left = construct(start, mid);
		root->right = construct(mid + 1, end);
		return root;
	}

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		N = preorder.size();
		if (N == 0) return NULL;
		pos.clear();
		this->preorder = preorder; this->inorder = inorder;
		N = preorder.size();
		for (int i = 0; i < N; i++)
			pos[inorder[i]] = i;
		nxt = 0;
		return construct(0, N);
    }
};

int main() {
	int preorder[] = {1, 2};
	int inorder[] = {2, 1};
	vector<int> pre(preorder, preorder + 2);
	vector<int> in(inorder, inorder + 2);
	Solution sol;
	TreeNode *root = sol.buildTree(pre, in);
	return 0;
}


