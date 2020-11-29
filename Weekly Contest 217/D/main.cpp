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

const int MAXN = 3200000;
const int MAXM = 100005;
pair<int, int> vec[MAXN];
int cnt[MAXM];
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        int m = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (x & 1) {
                vec[m++] = {x, i};
                vec[m++] = {x * 2, i};
                // vec.push_back({x, i});
                // vec.push_back({x * 2, i});
            } else {
                while (x % 2 == 0) {
                    // vec.push_back({x, i});
                    vec[m++] = {x, i};
                    x /= 2;
                }
                // vec.push_back({x, i});
                vec[m++] = {x, i};
            }
        }

        sort(vec, vec + m);
        // sort(vec.begin(), vec.end());
        // for (int i = 0; i < vec.size(); i++) {
        //     cout << vec[i].first << " " << vec[i].second << endl;
        // }
        int res = INT_MAX, r = 0, tot = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int l = 0; l < m; l++) {
            while (r < m && tot != n) {
                if (cnt[vec[r].second] == 0) {
                    tot++;
                }
                cnt[vec[r].second]++;
                r++;
            }
            if (tot == n) {
                if (vec[r - 1].first - vec[l].first < res) {
                    res = vec[r - 1].first - vec[l].first;
                }
            }
            cnt[vec[l].second]--;
            if (cnt[vec[l].second] == 0) {
                tot--;
            }
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

