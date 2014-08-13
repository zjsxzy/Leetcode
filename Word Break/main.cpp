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
#include <unordered_set>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

/*
 * Description: Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 *
 * Solution: Trie tree + dp.
 *
 */
const int MAXN = 1000;
struct Trie {
    struct Tnode {
        int next[26];
        int terminate;
    }chd[MAXN * 600];
    int size;

    void init() {
        size = 1;
        memset(chd[0].next, 0, sizeof(chd[0].next));
        chd[0].terminate = -1;
    }

    void insert(string s, int id) {
        int p = 0;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if (!chd[p].next[c]) {
                memset(chd[size].next, 0, sizeof(chd[size].next));
                chd[size].terminate = -1;
                chd[p].next[c] = size++;
            }
            p = chd[p].next[c];
        }
        chd[p].terminate = id;
    }

}trie;
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) { 
		trie.init();
		int i = 1;
		FOREACH(it, dict) {
			trie.insert(*it, i++);
		}
		vector<bool> canBreak(s.size() + 1);
		canBreak[s.size()] = true;
		for (int i = s.size() - 1; i >= 0; i--) {
			canBreak[i] = false;
			int p = 0;
			for (int j = i; j < s.size(); j++) {
				int c = s[j] - 'a';
				if (trie.chd[p].next[c]) {
					p = trie.chd[p].next[c];
				} else break;
				if (trie.chd[p].terminate > 0 && canBreak[j + 1]) {
					canBreak[i] = true;
					break;
				}
			}
		}
		return canBreak[0];
    }
};
int main() {
	Solution sol;
	unordered_set<string> dict;
	dict.insert("leetcode"); dict.insert("code");
	cout << sol.wordBreak("leetcode", dict) << endl;
	return 0;
}

