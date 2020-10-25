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
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size();
        map<char, int> cnt;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (cnt.find(keysPressed[i]) == cnt.end()) {
                cnt[keysPressed[i]] = releaseTimes[i] - cur;
            } else {
                if (releaseTimes[i] - cur > cnt[keysPressed[i]]) {
                    cnt[keysPressed[i]] = releaseTimes[i] - cur;
                }
            }
            cur = releaseTimes[i];
        }
        int mx = 0;
        char res;
        for (auto it : cnt) {
            if (it.second >= mx) {
                mx = it.second;
                res = it.first;
            }
        }
        return res;
    }
};

int main() {
}

