#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int i = 0, j = 0, d = 0;
        while (head) {
            // cout << i << ' ' << j << ' ' << head->val << endl;
            ans[i][j] = head->val;
            int ni = i + dx[d], nj = j + dy[d];
            if (ni >= m || ni < 0 || nj >= n || nj < 0 || ans[ni][nj] > -1) {
                d = (d + 1) % 4;
            }
            head = head->next;
            i += dx[d];
            j += dy[d];
        }
        return ans;
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

