#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 200005;
struct Trie {
    struct Tnode {
        int next[2];
        int terminate;
    }chd[MAXN * 32];
    int size;

    void init() {
        size = 1;
        memset(chd[0].next, 0, sizeof(chd[0].next));
        chd[0].terminate = -1;
    }

    void insert(int x, int id) {
        int p = 0;
        for (int i = 31; i >= 0; i--) {
            int c = (x >> i) & 1;
            if (!chd[p].next[c]) {
                memset(chd[size].next, 0, sizeof(chd[size].next));
                chd[size].terminate = -1;
                chd[p].next[c] = size++;
            }
            p = chd[p].next[c];
        }
        chd[p].terminate = id;
    }

    int find(int x) {
        int p = 0;
        for (int i = 31; i >= 0; i--) {
            int c = (x >> i) & 1;
            if (chd[p].next[c ^ 1]) {
                p = chd[p].next[c ^ 1];
            } else {
                p = chd[p].next[c];
            }
        }
        return chd[p].terminate;
    }
}trie;
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        trie.init();
        for (auto x: nums) {
            trie.insert(x, x);
        }
        int res = 0;
        for (auto x: nums) {
            int t = trie.find(x);
            // cout << x << ' ' << t << endl;
            res = max(res, t ^ x);
        }
        return res;
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

