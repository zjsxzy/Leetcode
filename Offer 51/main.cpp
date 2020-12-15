#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 50005;
struct BinaryIndexTree {
	int N;
	int C[maxn];

	void init(int N) {
		this->N = N;
		memset(C, 0, sizeof(C));
	}

	int lowbit(int x) {
		return x & (-x);
	}

	void add(int x, int num) {
		for (int i = x; i <= N; i += lowbit(i))
			C[i] += num;
	}

	int sum(int x) {
		int ret = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			ret += C[i];
		return ret;
	}
}bit;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec;
        for (auto &x : nums) {
            vec.push_back(x);
        }
        sort(vec.begin(), vec.end());
        vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
        for (auto &x : nums) {
            x = lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;
        }

        bit.init(n);
        long long res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res += (long long)i - bit.sum(nums[i]);
            bit.add(nums[i], 1);
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

