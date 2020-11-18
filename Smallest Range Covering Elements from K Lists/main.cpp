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
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<pair<int, int> > vec;
        for (int i = 0; i < n; i++) {
            for (auto x : nums[i]) {
                vec.push_back({x, i});
            }
        }

        sort(vec.begin(), vec.end());
        int res = INT_MAX, r = 0, tot = 0;
        pair<int, int> resp;
        map<int, int> cnt;
        for (int l = 0; l < vec.size(); l++) {
            while (r < vec.size() && tot != n) {
                if (cnt.find(vec[r].second) == cnt.end() || cnt[vec[r].second] == 0) {
                    tot++;
                }
                cnt[vec[r].second]++;
                r++;
            }
            if (tot == n) {
                if (vec[r - 1].first - vec[l].first < res) {
                    res = vec[r - 1].first - vec[l].first;
                    resp = {vec[l].first, vec[r - 1].first};
                }
            }
            cnt[vec[l].second]--;
            if (cnt[vec[l].second] == 0) {
                tot--;
            }
        }
        vector<int> ans;
        ans.push_back(resp.first);
        ans.push_back(resp.second);
        return ans;
    }
};