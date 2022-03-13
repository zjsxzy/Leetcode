#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
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
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        for (int i = 0; i < queries.size(); i++) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [] (const vector<int> &a, vector<int> &b){
              return a[2] < b[2];
            });

        sort(edgeList.begin(), edgeList.end(), [] (const vector<int> &a, vector<int> &b) {
              return a[2] < b[2];
            });

        DisJointSet uf;
        uf.init(n);
        int idx = 0;
        vector<bool> res(queries.size());
        for (int i = 0, j = 0; i < edgeList.size(); i = j) {
            while (j < edgeList.size() && edgeList[j][2] < queries[idx][2]) {
                uf.Union(edgeList[j][0], edgeList[j][1]);
                j++;
            }
            bool flag = uf.Find(queries[idx][0]) == uf.Find(queries[idx][1]);
            res[queries[idx][3]] = flag;
            idx++;
            if (idx == queries.size()) break;
        }
        while (idx < queries.size()) {
            bool flag = uf.Find(queries[idx][0]) == uf.Find(queries[idx][1]);
            res[queries[idx][3]] = flag;
            idx++;
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

