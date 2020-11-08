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

const int MOD = 1000000007;
class Solution {
public:
    int orders;
    LL res;

    void f(LL t, LL s, LL n) {
        LL sum = (s + 1 + t) * (t - s) / 2 * n;
        if (orders >= n * (t - s)) {
            orders -= n * (t - s);
            res = (res + sum) % MOD;
        } else {
            LL a = orders / n, b = orders % n;
            orders = 0;
            res = (res + (t - a + 1 + t) * a / 2 * n) % MOD;
            res = (res + (t - a) * b) % MOD;
        }
    }

    int maxProfit(vector<int>& inventory, int orders) {
        int n = inventory.size();
        this->orders = orders;
        sort(inventory.begin(), inventory.end());
        reverse(inventory.begin(), inventory.end());
        res = 0;
        for (int i = 0; i < n; ) {
            LL t = inventory[i];
            int j = i + 1;
            while (j < n && inventory[j] == t) {
                j++;
            }
            LL s;
            if (j == n) s = 0;
            else s = inventory[j];
            // cout << i << " " << t << " " << j << " " << s << endl;
            f(t, s, j);
            // cout << this->orders << " " << f(t, s, i + 1) << " " << res << endl;
            if (this->orders == 0) return res;
            i = j;
        }
        return res;
    }
};

int main() {
    Solution sol;
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << sol.maxProfit(v, k) << endl;
    return 0;
}

