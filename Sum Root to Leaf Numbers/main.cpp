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
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 * Find the total sum of all root-to-leaf numbers.
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
    int sumNumbers(TreeNode *root) {
		sum = 0;
		dfs(root, 0);
		return sum;
    }
	
	void dfs(TreeNode *p, int val) {
		if (p == NULL) return;
		bool leaf = true;
		val = val * 10 + p->val;
		if (p->left != NULL) {
			leaf = false;
			dfs(p->left, val);
		}
		if (p->right != NULL) {
			leaf = false;
			dfs(p->right, val);
		}
		if (leaf) {
			sum += val;
		}
	}
	
	int sum;
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	return 0;
}

