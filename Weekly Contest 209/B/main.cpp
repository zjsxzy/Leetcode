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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    bool flag;
    map<int, vector<int> > level;

    void dfs(TreeNode* p, int l) {
        if (p == NULL) return;
        if (!flag) return;
        // cout << p->val << " " << l << endl;
        level[l].push_back(p->val);
        dfs(p->left, l + 1);
        dfs(p->right, l + 1);
    }

    bool isEvenOddTree(TreeNode* root) {
        flag = true;
        dfs(root, 0);
        for (auto it = level.begin(); it != level.end(); it++) {
            cout << it->first << endl;
            if (it->first % 2 == 0) {
                for (auto x : it->second) {
                    if (x % 2 == 0) {
                        flag = false;
                        break;
                    }
                }
                for (int j = 0; j < it->second.size() - 1; j++) {
                    if (it->second[j] >= it->second[j + 1]) {
                        flag = false;
                        break;
                    }
                }
            } else {
                for (auto x : it->second) {
                    if (x % 2 == 1) {
                        flag = false;
                        break;
                    }
                }
                for (int j = 0; j < it->second.size() - 1; j++) {
                    if (it->second[j] <= it->second[j + 1]) {
                        flag = false;
                        break;
                    }
                }
            }
        }
        return flag;
    }
};
int main() {
}

