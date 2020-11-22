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
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        vector<int> sum_odd(n), sum_even(n);
        sum_even[0] = nums[0]; sum_even[1] = sum_even[0];
        sum_odd[0] = 0; sum_odd[1] = nums[1];
        for (int i = 2; i < n; i++) {
            if (i % 2) {
                sum_odd[i] = sum_odd[i - 1] + nums[i];
                sum_even[i] = sum_even[i - 1];
            } else {
                sum_even[i] = sum_even[i - 1] + nums[i];
                sum_odd[i] = sum_odd[i - 1];
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            int s = sum_odd[i] + (sum_even[n - 1] - sum_even[i]);
            if (i % 2) s -= nums[i];
            int t = sum_even[i] + (sum_odd[n - 1] - sum_odd[i]);
            if (i % 2 == 0) t -= nums[i];
            // cout << i << " " << s << " " << endl;
            if (s == t) res++;
        }
        return res;
    }
};

int main() {
}

