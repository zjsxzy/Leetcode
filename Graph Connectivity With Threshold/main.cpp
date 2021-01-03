#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 10005;
struct DisJointSet{
	int rank[maxn], parent[maxn];

	void init(int n) {
		for (int i = 1; i <= n; i++) {
			rank[i] = 0;
			parent[i] = i;
		}
	}

	int Find(int x) {
		if (parent[x] == x) return x;
		return parent[x] = Find(parent[x]);
	}

	void Union(int x, int y) {
		x = Find(x);
		y = Find(y);

		if (x == y) return;

		if (rank[x] >= rank[y]) {
			parent[y] = x;
			if (rank[x] == rank[y])
				rank[x]++;
		}
		else {
			parent[x] = y;
		}
	}

	int count(int n) {
		int ret = 0;
		for (int i = 0; i < n; i++)
			ret += Find(i) == i;
		return ret;
	}
}uf;

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        uf.init(n);
        for (int z = threshold + 1; z <= n; z++) {
            for (int a = z, b = 2 * z; b <= n; a += z, b += z) {
                uf.Union(a, b);
            }
        }

        vector<bool> res;
        for (auto &x : queries) {
            int a = x[0], b = x[1];
            res.push_back(uf.Find(a) == uf.Find(b));
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

