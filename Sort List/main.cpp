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
 * Sort a linked list in O(n log n) time using constant space complexity.
 *
 * Solution:
 * Implementation of merge sort with lists. Find middle node using fast/slow pointers.
 *
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
		ListNode *slow = head, *fast = head;
		while (fast->next && fast->next->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode *head2 = slow->next;
		slow->next = NULL;
		head = sortList(head);
		head2 = sortList(head2);
		return merge(head, head2);
    }
	
	ListNode *merge(ListNode *head, ListNode *head2) {
		ListNode *newHead = NULL, *prev = NULL;
		while (head && head2) {
			if (head->val < head2->val) {
				if (!newHead) newHead = head;
				if (prev) prev->next = head;
				prev = head;
				head = head->next;
			} else {
				if (!newHead) newHead = head2;
				if (prev) prev->next = head2;
				prev = head2;
				head2 = head2->next;
			}
		}
		if (head) prev->next = head;
		if (head2) prev->next = head2;
		return newHead;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	return 0;
}

