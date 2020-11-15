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

class Solution {
public:

    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> arr(n + 1);
        for (int i = 0; i < n; i++) {
            arr[i + 1] = nums[i];
            arr.push_back(nums[i]);
        }
        vector<int> sum(arr.size());
        for (int i = 1; i <= n * 2; i++) {
            sum[i] = sum[i - 1] + arr[i];
        }

        int res = -1;
        int l = 1, r = 2;
        for (; l <= 2 * n; l++) {
            while (r - l <= n && r <= 2 * n && sum[r] - sum[l] < x) {
                r++;
            }
            if (l <= n && r >= n && r - l <= n) {
                if (sum[r] - sum[l] == x) {
                    if (res == -1 || r - l < res) {
                        res = r - l;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}

