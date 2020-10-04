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
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        for (int x = 0; x <= 1000; x++) {
            int tot = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] >= x) {
                    tot++;
                }
            }
            if (tot == x) return x;
        }
        return -1;
    }
};

int main() {
    return 0;
}

