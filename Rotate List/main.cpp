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
 * Given a list, rotate the list to the right by k places, where k is non-negative.
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
    ListNode *rotateRight(ListNode *head, int k) {
		if (head == NULL) return NULL;
		int n = length(head); 
		k %= n;
		if (k == 0) return head;
		ListNode *p1 = head, *p2 = head;
		while (k > 0) {
			p2 = p2->next;
			k--;
		}
		while (p2->next != NULL) {
			p1 = p1->next;
			p2 = p2->next;
		}
		p2->next = head;
		head = p1->next;
		p1->next = NULL;
		return head;
    }
	int length(ListNode *head) {
		int n = 0;
		while (head != NULL) {
			n++;
			head = head->next;
		}
		return n;
	}
};
int main() {
}

