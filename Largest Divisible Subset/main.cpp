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
    vector<int> result;

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n), prev(n);
        result.clear();
        if (n == 0) return result;
        dp[0] = 1, prev[0] = 0;
        int largest = 1, position = 0;
        for (int i = 1; i < n; i++) {
            prev[i] = i;
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > largest) {
                largest = dp[i];
                position = i;
            }
            // printf("%d %d\n", largest, position);
            // printf("%d %d %d\n", i, dp[i], prev[i]);
        }
        recur(position, nums, prev);
        sort(result.begin(), result.end());
        return result;
    }

    void recur(int pos, vector<int>& nums, vector<int>& prev) {
        result.push_back(nums[pos]);
        if (pos == prev[pos]) {
            return;
        }
        else recur(prev[pos], nums, prev);
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	return 0;
}
