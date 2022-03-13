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
    set<string> res;
    void find(string &s, int a, int b) {
        string t = s;
        // op 1
        for (int i = 1; i < t.size(); i += 2) {
            t[i] = '0' + ((s[i] - '0' + a) % 10);
        }
        if (res.find(t) == res.end()) {
            res.insert(t);
            find(t, a, b);
        }
        // op 2
        t = s.substr(s.size() - b, b) + s.substr(0, s.size() - b);
        if (res.find(t) == res.end()) {
            res.insert(t);
            find(t, a, b);
        }
    }
    string findLexSmallestString(string s, int a, int b) {
        res.clear();
        find(s, a, b);
        return *res.begin();
    }
};

int main() {
    Solution sol;
    string s = sol.findLexSmallestString("43987654", 7, 3);
    cout << s << endl;
    return 0;
}

