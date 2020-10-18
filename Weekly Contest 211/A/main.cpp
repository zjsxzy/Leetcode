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
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        map<char, vector<int> > mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]].push_back(i);
        }
        int res = -1;
        for (auto x : mp) {
            int t = x.second.size();
            if (t > 1) {
                if (x.second[t - 1] - x.second[0] > res) {
                    res = x.second[t - 1] - x.second[0] - 1;
                }
            }
        }
        return res;
    }
};

int main() {
}

