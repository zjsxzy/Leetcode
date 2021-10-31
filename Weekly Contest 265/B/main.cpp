#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
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
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> d;
        ListNode* p = head;
        int i = 0, prev;
        while (p != NULL) {

            if (p->next != NULL && i > 0) {
                // cout << i << " " << p->val << " " << prev << endl;
                if (p->val > prev && p->val > p->next->val) {
                    d.push_back(i);
                }
                if (p->val < prev && p->val < p->next->val) {
                    d.push_back(i);
                }
            }
            if (p->next != NULL) {
                prev = p->val;
                p = p->next;
                i++;
            } else {
                break;
            }
        }


        if (d.size() < 2) {
            vector<int> res;
            res.push_back(-1); res.push_back(-1);
            return res;
        } else {
            int n = d.size();
            int mn = INT_MAX;
            for (int i = 1; i < n; i++) {
                if (d[i] - d[i - 1] < mn) mn = d[i] - d[i - 1];
            }
            vector<int> res;
            res.push_back(mn); res.push_back(d[n - 1] - d[0]);
            return res;
        }
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

