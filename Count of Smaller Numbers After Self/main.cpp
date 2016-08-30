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

struct BinaryIndexTree {
	int N;
	vector<int> C;

	void init(int N) {
		this->N = N;
		C.clear();
		C.resize(N + 1);
	}

	int lowbit(int x) {
		return x & (-x);
	}

	void add(int x, int num) {
		for (int i = x; i <= N; i += lowbit(i))
			C[i] += num;
	}

	int sum(int x) {
		if (x == 0) return 0;
		int ret = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			ret += C[i];
		return ret;
	}
}bit;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
	    vector<int> num;
	    for (int i = 0; i < nums.size(); i++) {
		    num.push_back(nums[i]);
	    }
	    sort(num.begin(), num.end());
        num.resize(unique(num.begin(), num.end()) - num.begin());
	    for (int i = 0; i < nums.size(); i++) {
		    nums[i] = lower_bound(num.begin(), num.end(), nums[i]) - num.begin() + 1;
	    }
		bit.init(num.size());
		vector<int> res;
		for (int i = nums.size() - 1; i >= 0; i--) {
			int count = bit.sum(nums[i] - 1);
			res.push_back(count);
			bit.add(nums[i], 1);
		}
		reverse(res.begin(), res.end());
		return res;
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	return 0;
}
