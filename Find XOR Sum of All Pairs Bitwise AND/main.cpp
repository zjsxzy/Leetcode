#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();

        vector<int> cnt2(32);
        for (int i = 0; i < 31; i++) {
            int sum = 0;
            for (auto b : arr2) {
                if ((b >> i) & 1) {
                    sum++;
                }
            }
            cnt2[i] = sum;
        }

        long long res = 0;
        for (int i = 0; i < 31; i++) {
            int sum = 0;
            for (auto a : arr1) {
                if ((a >> i) & 1) {
                    sum++;
                }
            }
            if (sum % 2 == 1 && cnt2[i] % 2 == 1) res += (1 << i);
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

