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

const int maxn = 100005;
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
const int MOD = 1000000007;
class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int n = instructions.size();
        map<int, int> cnt;
        int N = 100002;
        bit.init(N);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int x = instructions[i];
            int s = bit.sum(x);
            int t = i;
            if (cnt.find(x) != cnt.end()) {
                s -= cnt[x];
                t -= cnt[x];
            }
            t -= s;
            res = (res + min(s, t)) % MOD;
            cnt[x]++;
            bit.add(x, 1);
        }
        return res;
    }
};

int main() {
}

