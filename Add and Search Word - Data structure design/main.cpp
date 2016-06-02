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

const int MAXN = 100;
struct Tnode {
    int next[26];
    int terminate;
}chd[MAXN * 600];
int size;
bool Find;
class WordDictionary {
public:

    WordDictionary() {
        size = 1;
        memset(chd[0].next, 0, sizeof(chd[0].next));
        chd[0].terminate = -1;
    }

    // Adds a word into the data structure.
    void addWord(string word) {
		int p = 0;
		for (int i = 0; i < word.size(); i++) {
			int c = word[i] - 'a';
			// cout << p << " ";
			if (!chd[p].next[c]) {
				memset(chd[size].next, 0, sizeof(chd[size].next));
				chd[size].terminate = -1;
				chd[p].next[c] = size++;
			}
			p = chd[p].next[c];
		}
		chd[p].terminate = 1;
		// cout << p << endl;
        // cout << p << " " << chd[p].terminate << endl;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
		Find = false;
		dfs(word, 0, 0);
		return Find;
    }

	void dfs(string word, int p, int k) {
        // cout << p << " " << k << " " << word[k] << endl;
		if (Find) return;
		if (k == word.size()) {
			if (chd[p].terminate == 1) {
				Find = true;
			}
			return;
		}
		if (word[k] == '.') {
			for (int c = 0; c < 26; c++) {
				if (chd[p].next[c]) {
                    int next_p = chd[p].next[c];
					dfs(word, next_p, k + 1);
				}
			}
		} else {
			int c = word[k] - 'a';
			if (chd[p].next[c]) {
                int next_p = chd[p].next[c];
				dfs(word, next_p, k + 1);
			}
		}
	}
};
int main() {
	WordDictionary wordDictionary;
	// wordDictionary.addWord("at");
	// wordDictionary.addWord("and");
	// wordDictionary.addWord("an");
	wordDictionary.addWord("add");
	cout << wordDictionary.search("a") << endl;
	cout << wordDictionary.search(".at") << endl;
	wordDictionary.addWord("bat");
	cout << wordDictionary.search(".at") << endl;
	// wordDictionary.addWord("bad");
	// wordDictionary.addWord("dad");
	// wordDictionary.addWord("mad");
	// cout << wordDictionary.search("pad") << endl;
	// cout << wordDictionary.search("bad") << endl;
	// cout << wordDictionary.search(".ad") << endl;
	// cout << wordDictionary.search("b..") << endl;
	//     cout << wordDictionary.search("...") << endl;
	return 0;
}

