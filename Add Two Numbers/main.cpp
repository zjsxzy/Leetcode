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
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * Solution:
 * Brute force
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		int val = l1->val + l2->val;
		ListNode *head = new ListNode(val % 10);
		ListNode *tail = head;
		val /= 10;
		l1 = l1->next;
		l2 = l2->next;
		while (l1 != NULL && l2 != NULL) {
			val += l1->val + l2->val;
			tail = tail->next = new ListNode(val % 10);
			val /= 10;
			l1 = l1->next;
			l2 = l2->next;
		}
		ListNode *l = (l1 != NULL ? l1 : l2);
		while (l != NULL) {
			val += l->val;
			tail = tail->next = new ListNode(val % 10);
			val /= 10;
			l = l->next;
		}
		if (val > 0) {
			tail = tail->next = new ListNode(val);
		}
		return head;
    }
};
int main() {
	ListNode *a1 = new ListNode(1), *a2 = new ListNode(8), *a3 = new ListNode(3);
	ListNode *b1 = new ListNode(7), *b2 = new ListNode(1);
	a1->next = a2; a2->next = a3;
	b1->next = b2;
	Solution sol;
	ListNode *head = sol.addTwoNumbers(a1, b1);
	while (head != NULL) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << endl;
	return 0;
}

