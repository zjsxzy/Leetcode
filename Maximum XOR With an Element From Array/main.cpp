#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 100005;
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
        for (int i = 30; i >= 0; i--) {
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
        for (int i = 30; i >= 0; i--) {
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        trie.init();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < queries.size(); i++) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        vector<int> res(queries.size());
        int i = 0;
        for (auto &q : queries) {
            int x = q[0], m = q[1], idx = q[2];
            while (i < nums.size() && nums[i] <= m) {
                trie.insert(nums[i], nums[i]);
                i++;
            }
            if (trie.size == 1) { // empty tree
                res[idx] = -1;
            } else {
                int t = trie.find(x);
                res[idx] = x ^ t;
            }
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
    solve();
    return 0;
}

