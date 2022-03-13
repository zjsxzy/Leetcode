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
typedef long long LL;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> cnt;
        for (auto x : nums) {
            cnt[x]++;
        }
        int res = 0;
        for (auto x : cnt) {
            int y = k - x.first;
            if (cnt.find(y) != cnt.end()) {
                if (x.first != y) {
                    res += min(x.second, cnt[y]);
                    cnt[y] = 0;
                } else {
                    res += x.second / 2;
                    cnt[x.first] = 0;
                }
            }
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

