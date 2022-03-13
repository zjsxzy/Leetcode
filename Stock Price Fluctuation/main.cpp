#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class StockPrice {
public:
    set<pair<int, int>> p;
    map<int, int> ti;

    StockPrice() {
        p.clear();
        ti.clear();
    }

    void update(int timestamp, int price) {
        int old_price = ti[timestamp];
        ti[timestamp] = price;
        p.erase({old_price, timestamp});
        p.insert({price, timestamp});
    }

    int current() {
        if (ti.empty()) return 0;
        auto p = ti.end();
        p--;
        return p->second;
    }

    int maximum() {
        if (p.empty()) return 0;
        auto x = p.end();
        x--;
        return x->first;
    }

    int minimum() {
        if (p.empty()) return 0;
        auto x = p.begin();
        return x->first;
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

