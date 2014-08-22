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
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
		ret.clear();
		this->sum = sum;
        if (root == NULL) return ret;
		vector<int> path;
		dfs(root, 0, path);
		return ret;
    }
	
	void dfs(TreeNode *p, int cur, vector<int> path) {
		cur += p->val;
		path.push_back(p->val);
		bool leaf = true;
		if (p->left != NULL) {
			leaf = false;
			dfs(p->left, cur, path);
		}
		if (p->right != NULL) {
			leaf = false;
			dfs(p->right, cur, path);
		}
		if (leaf && cur == sum) {
			ret.push_back(path);
		}
	}
	
	int sum;
	vector<vector<int> > ret;
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	return 0;
}

