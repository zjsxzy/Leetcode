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
 * Description: Merge two sorted list.
 *
 * Solution: Brute force.
 *
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode *head = new ListNode(0);
		ListNode *tail = head;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				tail->next = l1;
				tail = l1;
				l1 = l1->next;
			} else {
				tail->next = l2;
				tail = l2;
				l2 = l2->next;
			}
		}
		tail->next = l1 ? l1 : l2;
		return head->next;
    }
};
int main() {
}

