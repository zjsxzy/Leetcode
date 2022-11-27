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
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode*> vec;
        ListNode* p = head;
        while (p != NULL) {
            vec.push_back(p);
            p = p->next;
        }
        vector<ListNode*> st;
        reverse(vec.begin(), vec.end());
        int n = vec.size();
        for (int i = 0; i < n; i++) {
            if (st.size() == 0 || vec[i]->val >= st.back()->val) {
                st.push_back(vec[i]);
            }
        }
        reverse(st.begin(), st.end());
        int m = st.size();
        for (int i = 0; i < m - 1; i++) st[i]->next = st[i + 1];
        // for (auto x: st) cout << x->val << endl;
        return st[0];
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

