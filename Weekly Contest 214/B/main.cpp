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
    int minDeletions(string s) {
        map<char, int> cnt;
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i]]++;
        }
        map<int, int> mp;
        for (auto x : cnt) {
            mp[x.second]++;
        }
        queue<pair<int, int> > q;
        for (auto x : mp) {
            if (x.second > 1)
                q.push({x.first, x.second});
        }
        int res = 0;
        while (!q.empty()) {
            auto x = q.front(); q.pop();
            int s = x.second;
            for (int i = 1; i < s; i++) {
                int t = x.first;
                // cout << t << " " << s << endl;
                while (mp.find(t) != mp.end()) {
                    t--;
                    res++;
                }
                if (t > 0) mp[t] = s;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.minDeletions("ceabaacb") << endl;
    return 0;
}

