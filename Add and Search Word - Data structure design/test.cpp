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

class TrieNode {
public:
    bool iskey;
    TrieNode* children[26];
    TrieNode() {
        iskey = false;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root  = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.size(); i++) {
            if (node -> children[word[i] - 'a'] == NULL) {
                node -> children[word[i] - 'a'] = new TrieNode();
            }
            node = node -> children[word[i] - 'a'];
        }
        node -> iskey = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search_(TrieNode* node, string word) {
		// cout << word[0] << endl;
        if (node == NULL) return false;

        int i;
        for (i = 0; i < 26; i++) {	
            if (node -> children[i] != NULL) break;
        }
        if (i == 26) return false;
        // cout << 1 << endl;

        if (word.size() == 1) {
            if (word[0] == '.') {
				for (int i = 0; i < 26; i++) {
					if (node->children[i] != NULL && node->children[i]->iskey) return true;
				}
				return false;
                // return true;
            }
            if (node -> children[word[0] - 'a'] != NULL) 
                return (node -> children[word[0] - 'a']) -> iskey;
            else return false;
        } 
        else{
            if (word[0] != '.') {
                node = node -> children[word[0] - 'a'];
                int n = word.size();
                word = word.substr(1, n-1);
                return search_(node, word);
            }
            else {
				// TrieNode* temp;
                for (int i = 0; i < 26; i++) {
                    TrieNode* temp = node -> children[i];
					if (temp == NULL) continue;
                    int n = word.size();
                    string sub_word = word.substr(1, n-1);
					// cout << word << endl;
                    if(search_(temp, sub_word)) return true;
                }
                return false;
            }
        }
    }
    bool search(string word) {
        return search_(root, word);
    }
};
int main() {
	WordDictionary wordDictionary;
	wordDictionary.addWord("at");
	wordDictionary.addWord("and");
	wordDictionary.addWord("an");
	wordDictionary.addWord("add");
	// cout << wordDictionary.search("a") << endl;
	// cout << wordDictionary.search(".at") << endl;
	wordDictionary.addWord("bat");
	// cout << wordDictionary.search(".at") << endl;
	cout << wordDictionary.search("b.") << endl;
}