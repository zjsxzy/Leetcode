#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define maxV 205
#define maxE 100 * maxV
const int inf = 0x3f3f3f3f;
struct Nod {
    int b, nxt;
    int cap;
    long long cst;
    void init(int b, int nxt, int cap, long long cst) {
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
    void addCap(int a, int b, int cap, long long cst) {
        // cout << a << ' ' << b << ' ' << cap << ' ' << cst << endl;
        buf[len].init(b, E[a], cap, cst);   E[a] = len ++;
        buf[len].init(a, E[b], 0,  -cst);   E[b] = len ++;
    }
    bool spfa(int source, int sink) {
        static queue<int> q;
        // static long long d[maxV];
        // memset(d,  63, sizeof(d));
        vector<long long> d(maxV, 1e12);
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
        return d[sink] != 1e12;
    }
    pair<int, long long> solve(int source, int sink) {
        long long minCost = 0;
        int maxFlow = 0;
        while(spfa(source, sink)) {
            int neck = inf;
            for(int t=p[sink]; t != -1; t = p[ buf[t^1].b ])
                neck = min(neck, buf[t].cap);
            maxFlow += neck;
            for(int t = p[sink]; t != -1; t = p[ buf[t^1].b ]) {
                buf[t].cap -= neck;
                buf[t^1].cap += neck;
                minCost += buf[t].cst * (long long)neck;
            }
        }
        return make_pair(maxFlow, minCost);
    }
} mcmf;


class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size(), m = factory.size();
        int source = n + m, sink = n + m + 1;
        mcmf.init(n + m + 2);
        for (int i = 0; i < n; i++) {
            mcmf.addCap(source, i, 1, 0);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mcmf.addCap(i, n + j, 1, abs(robot[i] - factory[j][0]));
            }
        }
        for (int j = 0; j < m; j++) {
            mcmf.addCap(n + j, sink, factory[j][1], 0);
        }
        auto res = mcmf.solve(source, sink);
        return res.second;
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

