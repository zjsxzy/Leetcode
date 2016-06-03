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

const int MAXN = 50005;
struct SegTree {

	int sum[MAXN << 2];

	int lson(int rt) {
		return rt << 1;
	}

	int rson(int rt) {
		return rt << 1 | 1;
	}

	void pushUp(int rt) {
		sum[rt] = sum[lson(rt)] + sum[rson(rt)];
	}

	void build(int l, int r, int rt) {
		sum[rt] = 0;
		if (l == r)  return;
		int mid = (l + r) >> 1;
		build(l, mid, lson(rt));
		build(mid + 1, r, rson(rt));
		pushUp(rt);
	}

	void update(int pos, int c, int l, int r, int rt) {
        // cout << l << " " << r << " " << sum[rt] << endl;
        if (l == r) {
            sum[rt] += c;
            return;
        }
		int mid = (l + r) >> 1;
		if (pos <= mid) update(pos, c, l, mid, lson(rt));
        else update(pos, c, mid + 1, r, rson(rt));
		pushUp(rt);
	}

	int query(int L, int R, int l, int r, int rt) {
		if (L <= l && r <= R) {
			return sum[rt];
		}
		int mid = (l + r) >> 1;
		int res = 0;
		if (L <= mid) res += query(L, R, l, mid, lson(rt));
		if (mid < R) res += query(L, R, mid + 1, r, rson(rt));
		return res;
	}
}tree;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return (lower <= nums[0] && nums[0] <= upper);
        vector<long long> sum(n + 1);
        sum[0] = 0;
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }

        // discretize
        vector<long long> num;
        for (int i = 0; i < sum.size(); i++) {
            num.push_back(sum[i]);
            num.push_back(sum[i] - upper);
            num.push_back(sum[i] - lower);
        }
        sort(num.begin(), num.end());
        num.resize(unique(num.begin(), num.end()) - num.begin());
        int m = num.size();
        /*
        for (int i = 0; i < num.size(); i++) {
            cout << num[i] << " ";
        }
        cout << endl;
        */

        tree.build(1, m, 1);
        int res = 0;
        for (int i = 0; i < sum.size(); i++) {
            if (i > 0) {
                int left = lower_bound(num.begin(), num.end(), sum[i] - upper) - num.begin() + 1;
                int right = lower_bound(num.begin(), num.end(), sum[i] - lower) - num.begin() + 1;
                int temp = tree.query(left, right, 1, m, 1);
                res += temp;
                // cout << i << " " << left << " " << right << " " << temp << endl;
            }
            int pos = lower_bound(num.begin(), num.end(), sum[i]) - num.begin() + 1;
            tree.update(pos, 1, 1, m, 1);
            // cout << tree.sum[1] << endl;
        }
        return res;
    }
};
int main() {
    int nums[4] = {-2147483647, 0, -2147483647, 2147483647};
    vector<int> x(nums, nums + sizeof(nums) / sizeof(int));
    Solution sol;
    cout << sol.countRangeSum(x, -564, 3864) << endl;
	return 0;
}

