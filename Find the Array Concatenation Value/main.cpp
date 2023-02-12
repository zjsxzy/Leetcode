#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int n = nums.size(), i = 0, j = n - 1;
        long long res = 0;
        while (i <= j) {
            if (i != j) {
                res += stol(to_string(nums[i]) + to_string(nums[j]));
                i++;
                j--;
            } else {
                res += nums[i];
                break;
            }
        }
        return res;
    }
};

void solve() {
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

