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
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 *
 * Solution:
 * Implementation.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
		ListNode *cur = head, *last = NULL, *nxt = head;
		int iter = 0;
		while (iter < k && nxt != NULL) {
			iter++;
			nxt = nxt->next;
		}
		while (iter == k) {
			ListNode *prev = cur, *nlast = cur;
			cur = cur->next;
			while (cur != nxt) {
				ListNode *ncur = cur->next;
				cur->next = prev;
				prev = cur;
				cur = ncur;
			}
			if (last != NULL) last->next = prev;
			else head = prev;
			last = nlast;
			iter = 0;
			while (iter < k && nxt != NULL) {
				iter++;
				nxt = nxt->next;
			}
		}
		if (last != NULL) last->next = cur;
		return head;
    }
};
int main() {
}

