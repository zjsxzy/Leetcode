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

#define maxV 105
#define maxE 100 * maxV
const int inf = 0x3f3f3f3f;
struct Nod {
    int b, nxt;
    int cap, cst;
    void init(int b, int nxt, int cap,int cst) {
        this->b = b;
        this->nxt = nxt;
        this->cap = cap;
        this->cst = cst;
    }
};
struct MinCost {
    int E[maxV];        int n;
    Nod buf[maxE*2];    int len;

    int p[maxV];
    void init(int n) {
        this->n = n;
        memset(E, 255, sizeof(E));
        len = 0;
    }
    void addCap(int a, int b, int cap, int cst) {
        buf[len].init(b, E[a], cap, cst);   E[a] = len ++;
        buf[len].init(a, E[b], 0,  -cst);   E[b] = len ++;
    }
    bool spfa(int source, int sink) {
        static queue<int> q;
        static int d[maxV];
        memset(d,  63, sizeof(d));
        memset(p, 255, sizeof(p));

        d[source] = 0;
        q.push(source);
        int u, v;
        while(!q.empty()) {
            u = q.front();
            q.pop();
            for(int i = E[u]; i != -1; i = buf[i].nxt) {
                v = buf[i].b;
                if(buf[i].cap>0 && d[u]+buf[i].cst<d[v]) {
                    d[v] = d[u]+buf[i].cst;
                    p[v] = i;
                    q.push(v);
                }
            }
        }
        return d[sink] != inf;
    }
    pair<int, int> solve(int source, int sink) {
        int minCost = 0,maxFlow = 0;
        while(spfa(source, sink)) {
            int neck = inf;
            for(int t=p[sink]; t != -1; t = p[ buf[t^1].b ])
                neck = min(neck, buf[t].cap);
            maxFlow += neck;
            for(int t = p[sink]; t != -1; t = p[ buf[t^1].b ]) {
                buf[t].cap -= neck;
                buf[t^1].cap += neck;
                minCost += buf[t].cst * neck;
            }
        }
        return MP(maxFlow, minCost);
    }
} mcmf;

class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size(), m = cost[0].size();
        int s = n + m, t = n + m + 1;
        vector<int> lmin(n, INT_MAX), rmin(m, INT_MAX);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                lmin[i] = min(lmin[i], cost[i][j]);
                rmin[j] = min(rmin[j], cost[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += lmin[i];
        }
        for (int j = 0; j < m; j++) {
            ans += rmin[j];
        }
        mcmf.init(n + m + 2);
        for (int i = 0; i < n; i++) {
            mcmf.addCap(s, i, 1, 0);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (cost[i][j] - lmin[i] - rmin[j] < 0) {
                    mcmf.addCap(i, n + j, 1, cost[i][j] - lmin[i] - rmin[j]);
                }
            }
        }
        for (int j = 0; j < m; j++) {
            mcmf.addCap(n + j, t, 1, 0);
        }
        pair<int, int> res = mcmf.solve(s, t);
        return ans + res.second;
    }
};

int main() {
}

