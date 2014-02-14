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
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * Solution:
 * Two pointers.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode *cur = head->next->next, *prev = head;
		head->next->next = head;
		head = head->next;
		while (cur != NULL && cur->next != NULL) {
			ListNode *nxt = cur->next->next;
			prev->next = cur->next;
			cur->next->next = cur;
			prev = cur;
			cur = nxt;
		}
		prev->next = cur;
		return head;
    }
};
int main() {
}

