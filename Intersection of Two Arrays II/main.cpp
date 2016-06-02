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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++) {
            if (mp.find(nums1[i]) == mp.end()) {
                mp.insert(pair<int, int>(nums1[i], 1));
            } else {
                mp[nums1[i]]++;
            }
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (mp.find(nums2[i]) != mp.end()) {
                if (mp[nums2[i]] > 0) {
                    res.push_back(nums2[i]);
                    mp[nums2[i]]--;
                }
            }
        }
        return res;
    }
};
int main() {
}
