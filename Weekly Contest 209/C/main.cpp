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
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int n = points.size();
        int posx = location[0], posy = location[1];
        double PI = 2 * acos(0.0);
        vector<double> angs;
        int same = 0;
        for (int i = 0; i < n; i++) {
            int x = points[i][0], y = points[i][1];
            double ang = atan2(y - posy, x - posx) * 180 / PI;
            if (ang < 0) ang = 360 + ang;
            if (x == posx && y == posy) {
                same++;
            } else {
                angs.push_back(ang);
                angs.push_back(ang + 360);
            }
        }
        sort(angs.begin(), angs.end());
        int res = 0;
        for (int l = 0, r = 0; r < angs.size(); l++) {
            while (r < angs.size() && angs[r] - angs[l] <= angle && r - l < angs.size() / 2) {
                r++;
            }
            if (r - l > res) {
                res = r - l;
            }
        }
        return res + same;
    }
};

int main() {
}

