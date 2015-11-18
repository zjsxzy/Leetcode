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


const int MAXN = 10000 + 5;
class NumArray {
public:

    int sum[MAXN << 2];
    vector<int> nums;
    int n;

    NumArray(vector<int> &nums) {
        this->nums = nums;
        n = nums.size();
        if (n == 0) return;
        build(0, n - 1, 1);
    }

	int lson(int rt) { return rt << 1; }
    int rson(int rt) { return rt << 1 | 1; }
    void pushUp(int rt) {
        sum[rt] = sum[lson(rt)] + sum[rson(rt)];
    }

    void build(int l, int r, int rt) {
        sum[rt] = 0;
        if (l == r) {
            sum[rt] = nums[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, lson(rt));
        build(mid + 1, r, rson(rt));
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

    void updateValue(int pos, int val, int l, int r, int rt) {
        if (l == r) {
            sum[rt] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) updateValue(pos, val, l, mid, lson(rt));
        else updateValue(pos, val, mid + 1, r, rson(rt));
        pushUp(rt);
    }

    void update(int i, int val) {
        if (n == 0) return;
        updateValue(i, val, 0, n - 1, 1);
    }

    int sumRange(int i, int j) {
        if (n == 0) return 0;
        return query(i, j, 0, n - 1, 1);
    }
};

int main() {
    int myints[] = {1, 3, 5};
    vector<int> nums(myints, myints + sizeof(myints) / sizeof(int) );
    NumArray tree(nums);
    cout << tree.sumRange(0, 2) << endl;
    tree.update(1, 2);
    cout << tree.sumRange(0, 2) << endl;
	return 0;
}
