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

const int maxn = 100005;
struct DisJointSet{
	int rank[maxn], parent[maxn];

	void init(int n) {
		for (int i = 0; i < n; i++) {
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
}alice, bob;

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        alice.init(n); bob.init(n);
        vector<pair<int, int> > a_ed, b_ed;
        int res_a = 0, res_b = 0;
        for (auto e : edges) {
            if (e[0] == 3) {
                if (alice.Find(e[1] - 1) == alice.Find(e[2] - 1)) {
                    res_a++;
                } else {
                    alice.Union(e[1] - 1, e[2] - 1);
                    bob.Union(e[1] - 1, e[2] - 1);
                }
            } else if (e[0] == 1) {
                a_ed.push_back({e[1] - 1, e[2] - 1});
            } else if (e[0] == 2) {
                b_ed.push_back({e[1] - 1, e[2] - 1});
            }
        }
        for (auto e : a_ed) {
            if (alice.Find(e.first) == alice.Find(e.second)) {
                res_a++;
            } else {
                alice.Union(e.first, e.second);
            }
        }
        for (auto e : b_ed) {
            if (bob.Find(e.first) == bob.Find(e.second)) {
                res_b++;
            } else {
                bob.Union(e.first, e.second);
            }
        }
        if (alice.count(n) == 1 && bob.count(n) == 1) {
            return res_a + res_b;
        } else {
            return -1;
        }
    }
};

int main() {
}

