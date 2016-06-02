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

class Solution{
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        int tot = 0;
        for (int cur = 1; cur < num; cur <<= 1, tot++);
        for (int i = 0; i <= tot; i++) {
            if ((1 << i) <= num) res[1 << i] = 1;
        }
        int last = -1, count = 0;
        for (int i = 2; i <= num; i++) {
            if (res[i] > 0) {
                last = i;
                count = 1;
            } else {
                res[i] = res[last] + res[count];
                count++;
            }
        }
        for (int i = 0; i <= num; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        return res;
    }
};
int main() {
    Solution sol;
    vector<int> res = sol.countBits(5);
    return 0;
}

