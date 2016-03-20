/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* odd_head = odd;
        ListNode* even_head = even;
        int iter = 3;
        for (ListNode* curr = even->next; curr != NULL; curr = curr->next, iter++) {
            if (iter & 1) {
                // printf("odd %d\n", curr->val);
                odd->next = curr;
                odd = odd->next;
            } else {
                // printf("even %d\n", curr->val);
                even->next = curr;
                even = even->next;
            }
        }
        if (iter % 2 == 0) {
            even->next = NULL;
        }
        odd->next = even_head;
        return odd_head;
    }
};
