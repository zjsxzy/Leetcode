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
 * Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
 *
 * Solution:
 * Hashmap + two way linked list.
 */
struct Node {
	int key, value;
	Node *next, *prev;
	Node() {}
	Node(int key, int value) : key(key), value(value), next(NULL), prev(NULL) {}
};
class LRUCache{
public:
	int capacity, size;
	Node *head, *tail;
	map<int, Node*> mp;
    LRUCache(int capacity) {
		this->capacity = capacity;
		size = 0;
		head = NULL;
		tail = NULL;
		mp.clear();
    }
    
    int get(int key) {
		if (mp.find(key) == mp.end()) return -1;
		map<int, Node*>::iterator it = mp.find(key);
		Node *cur = (*it).second;
		remove(cur);
		addFront(cur);
		return cur->value;
    }
    
    void set(int key, int value) {
        Node *p;
		if (mp.find(key) != mp.end()) {
			map<int, Node*>::iterator it = mp.find(key);
			p = (*it).second;
			p->value = value;
			remove(p);
		} else {
			p = new Node(key, value);
			mp[key] = p;
			size++;
			if (size > capacity) {
				mp.erase(tail->key);
				remove(tail);
				size--;
			}
		}
		addFront(p);
    }

	void remove(Node *p) {
		if (p->prev != NULL)
			p->prev->next = p->next;
		else head = p->next;
		if (p->next != NULL)
			p->next->prev = p->prev;
		else tail = p->prev;
		p->next = p->prev = NULL;
	}

	void addFront(Node *p) {
		if (head != NULL) {
			p->next = head;
			head->prev = p;
			head = p;
		} else {
			head = tail = p;
		}
	}
};
int main() {
}

