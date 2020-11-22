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
    string getSmallestString(int n, int k) {
        string res;
        int rest = k;
        while (rest / 26 < n) {
            res += 'a';
            rest--;
            n--;
        }

        int d = rest / 26;
        if (rest % 26) d++;
        cout << rest << " " << d << " "<< n << " " << res << endl;
        if (d > n) res.erase(res.size() - 1);
        int z = rest / 26, b = rest % 26;
        if (b) res += 'a' + b;
        for (int i = 0; i < z; i++) {
            res += 'z';
        }
        return res;
    }
};

int main() {
}

