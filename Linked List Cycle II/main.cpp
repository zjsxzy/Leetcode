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

/**
 * Description:
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *
 * Solution:
 * Two pointers, one moves by one step, the other moves by two steps. When the two pointers meet at some place, the slow moves a+b distance while the fast one moves a+b+c+b, so we have 2(a+b)=a+b+c+b, which means a=c, then we find the beginning of the cycle by starting the slow one at the head of the list and moves with the fast one together. 
 *
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
		if (head == NULL) return NULL;
		ListNode *slow = head, *fast = head;
		while (fast->next != NULL && fast->next->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) break;
		}
		if (fast->next == NULL || fast->next->next == NULL) return NULL;
		slow = head;
		while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
		}
		return fast;
    }
};
int main() {
}

