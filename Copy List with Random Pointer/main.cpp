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
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 * Return a deep copy of the list.
 *
 * Solution:
 * Implementation. Add a new node to every origial node.
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL) return NULL;
		for (RandomListNode *p = head; p != NULL; ) {
			RandomListNode *r = new RandomListNode(p->label);
			r->next = p->next;
			r->random = p->random;
			p->next = r;
			p = r->next;
		}
		RandomListNode *newHead = head->next;
		for (RandomListNode *p = newHead; p != NULL; p = p->next != NULL ? p->next->next : NULL) {
			if (p->random != NULL)
				p->random = p->random->next;
		}
		for (RandomListNode *p1 = head, *p2 = newHead; p1 != NULL && p2 != NULL; p1 = p1->next, p2 = p2->next) {
			p1->next = p1->next->next;
			p2->next = p2->next != NULL ? p2->next->next : NULL;
		}
		return newHead;
    }
};
int main() {
}

