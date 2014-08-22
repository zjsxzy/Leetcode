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
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 * Solution:
 * Implementation.
 *
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
		if (head == NULL) return NULL;
		ListNode *prev = NULL, *cur = head;
		for (int i = 1; i < m; i++) {
			prev = cur;
			cur = cur->next;
		}
		ListNode *before = prev, *start = cur;
		prev = cur;
		cur = cur->next;
		for (int i = m + 1; i <= n; i++) {
			ListNode *temp = cur->next;
			cur->next = prev;
			prev = cur;
			cur = temp;
		}
		start->next = cur;
		if (before != NULL)
			before->next = prev;
		else head = prev;
		return head;
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	return 0;
}

