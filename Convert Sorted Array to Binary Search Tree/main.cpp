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
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 *
 * Solution:
 * Depth first search.
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
	vector<int> num;
    TreeNode *sortedArrayToBST(vector<int> &num) {
        this->num = num;
		if (num.size() == 0) return NULL;
		return dfs(0, num.size() - 1);
    }
	
	TreeNode *dfs(int l, int r) {
		TreeNode *p = new TreeNode(0);
		int mid = (l + r) >> 1;
		p->val = num[mid];
		if (l == r) {
			p->left = p->right = NULL;
			return p;
		} else if ((l != mid) && (r != mid)) {
			p->left = dfs(l, mid - 1);
			p->right = dfs(mid + 1, r);
			return p;
		} else if (l == mid) {
			p->left = NULL;
			p->right = dfs(mid + 1, r);
			return p;
		} else if (r == mid) {
			p->right = NULL;
			p->left = dfs(l, mid - 1);
			return p;
		}
		return NULL;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	return 0;
}

