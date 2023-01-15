#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 500 + 10;
int T , N , M;
int C[MAXN][MAXN];

int lowbit(int x) {
	return x & (-x);
}

int sum(int x , int y) {
	int ans = 0;
	for (int i = x ; i <= N ; i += lowbit(i))
	for (int j = y ; j <= N ; j += lowbit(j))
		ans += C[i][j];
	return ans;
}

void add(int x , int y , int num) {
	for (int i = x ; i > 0 ; i -= lowbit(i))
	for (int j = y ; j > 0 ; j -= lowbit(j))
		C[i][j] += num;
}

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        N = n; M = n;
        memset(C, 0, sizeof(C));
        for (auto v: queries) {
            int x1 = v[0] + 1, y1 = v[1] + 1, x2 = v[2] + 1, y2 = v[3] + 1;
            add(x2 , y2 , 1);
			add(x1 - 1 , y2 , -1);
			add(x2 , y1 - 1 , -1);
			add(x1 - 1 , y1 - 1 , 1);
        }
        vector<vector<int>> ans;
        for (int i = 1; i <= n; i++) {
            vector<int> s;
            for (int j = 1; j <= n; j++) {
                s.push_back(sum(i, j));
            }
            ans.push_back(s);
        }
        return ans;
    }
};

void solve() {
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

