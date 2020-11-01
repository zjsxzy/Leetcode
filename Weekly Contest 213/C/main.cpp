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
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        if (n == 0) return 0;
        for (int i = 1; i < n; i++) {
            if (heights[i - 1] >= heights[i]) {
                continue;
            } else {
                int diff = heights[i] - heights[i - 1];
                if (bricks >= diff) bricks -= diff;
                else if (ladders > 0) ladders--;
                else return i - 1;
            }
        }
        return n - 1;
    }
};

int main() {
    return 0;
}

