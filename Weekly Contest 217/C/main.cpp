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

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> arr(limit * 2 + 2);
        for (int i = 0; i < n / 2; i++) {
            int a = nums[i], b = nums[n - 1 - i];
            int lo = 1 + min(a, b), hi = limit + max(a, b);
            int sum = a + b;
            arr[lo]--;
            arr[sum]--;
            arr[sum + 1]++;
            arr[hi + 1]++;
        }
        int res = n, cur = n;
        for (int i = 2; i <= 2 * limit; i++) {
            cur += arr[i];
            res = min(res, cur);
        }
        return res;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    return 0;
}

