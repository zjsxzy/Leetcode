#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 1005;
struct Trie {
    struct Tnode {
        int next[26];
        int terminate;
    }chd[MAXN * 1005];
    int size;

    void init() {
        size = 1;
        memset(chd[0].next, 0, sizeof(chd[0].next));
        chd[0].terminate = 0;
    }

    void insert(string& s) {
        int p = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (!chd[p].next[c]) {
                memset(chd[size].next, 0, sizeof(chd[size].next));
                chd[size].terminate = 0;
                chd[p].next[c] = size++;
            }
            p = chd[p].next[c];
            chd[p].terminate++;
        }
    }

    int find(string& s) {
        int p = 0, n = s.size(), res = 0;
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            p = chd[p].next[c];
            res += chd[p].terminate;
        }
        return res;
    }
}trie;

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        trie.init();
        for (auto& s: words) {
            trie.insert(s);
        }
        vector<int> ans;
        for (auto& s: words) {
            int t = trie.find(s);
            ans.push_back(t);
        }
        return ans;
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

