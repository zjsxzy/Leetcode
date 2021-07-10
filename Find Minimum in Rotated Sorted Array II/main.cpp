#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int findMin(vector<int> &num) {
		int n = num.size();
		int lo = 0, hi = n - 1;
		while (lo < hi) {
			int mid = (lo + hi) >> 1;
			if (num[mid] > num[hi]) lo = mid + 1;
            else if (num[mid] < num[hi]) hi = mid;
			else hi = hi - 1;
		}
		return num[lo];
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

