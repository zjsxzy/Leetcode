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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    int sum;
    int sumOfLeftLeaves(TreeNode* root) {
        sum = 0;
        dfs(root, 0);
        return sum;
    }

    void dfs(TreeNode* p, int type) {
        if (p == NULL) return;
        if (type == -1 && p->left == NULL && p->right == NULL) {
            sum += p->val;
        }
        dfs(p->left, -1);
        dfs(p->right, 1);
    }
};

int main() {
}

